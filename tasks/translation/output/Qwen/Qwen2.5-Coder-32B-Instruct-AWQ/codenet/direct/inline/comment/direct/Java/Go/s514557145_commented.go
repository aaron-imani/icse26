package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var (
	tenmod []int64
	inv9   int64
)

type S struct {
	sum int64
	l   int
	r   int
}

func (s S) op(other S) S {
	sum := s.sum + other.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	return S{sum, min(s.l, other.l), max(s.r, other.r)}
}

func (s S) mapFunc(f F) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1])
	if c < 0 {
		c += MOD2
	}
	return S{(f.D * c % MOD2 * inv9) % MOD2, s.l, s.r}
}

type F struct {
	D int64
	N int
}

func (f F) composite(other F) F {
	return F{f.D, f.N}
}

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

func modPow(x, y int64) int64 {
	z := int64(1)
	for y > 0 {
		if y%2 == 0 {
			x = (x * x) % MOD2
			y /= 2
		} else {
			z = (z * x) % MOD2
			y--
		}
	}
	return z
}

type LazySegTree struct {
	N           int
	Log         int
	Op          func(S, S) S
	E           S
	Mapping     func(F, S) S
	Composition func(F, F) F
	Id          F
	Dat         []S
	Laz         []F
}

func NewLazySegTree(n int, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	k := 1
	for k < n {
		k <<= 1
	}
	lst := &LazySegTree{
		N:           k,
		Log:         bitLength(k),
		Op:          op,
		E:           e,
		Mapping:     mapping,
		Composition: composition,
		Id:          id,
		Dat:         make([]S, k<<1),
		Laz:         make([]F, k),
	}
	for i := range lst.Dat {
		lst.Dat[i] = e
	}
	for i := range lst.Laz {
		lst.Laz[i] = id
	}
	return lst
}

func NewLazySegTreeFromArray(dat []S, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	lst := NewLazySegTree(len(dat), op, e, mapping, composition, id)
	for i := range dat {
		lst.Dat[lst.N+i] = dat[i]
	}
	for i := lst.N - 1; i > 0; i-- {
		lst.Dat[i] = lst.Op(lst.Dat[i<<1|0], lst.Dat[i<<1|1])
	}
	return lst
}

func (lst *LazySegTree) push(k int) {
	if lst.Laz[k] == lst.Id {
		return
	}
	lk, rk := k<<1|0, k<<1|1
	lst.Dat[lk] = lst.Mapping(lst.Laz[k], lst.Dat[lk])
	lst.Dat[rk] = lst.Mapping(lst.Laz[k], lst.Dat[rk])
	if lk < lst.N {
		lst.Laz[lk] = lst.Composition(lst.Laz[k], lst.Laz[lk])
	}
	if rk < lst.N {
		lst.Laz[rk] = lst.Composition(lst.Laz[k], lst.Laz[rk])
	}
	lst.Laz[k] = lst.Id
}

func (lst *LazySegTree) pushTo(k int) {
	for i := lst.Log; i > 0; i-- {
		lst.push(k >> i)
	}
}

func (lst *LazySegTree) pushToRange(lk, rk int) {
	for i := lst.Log; i > 0; i-- {
		if ((lk >> i) << i) != lk {
			lst.push(lk >> i)
		}
		if ((rk >> i) << i) != rk {
			lst.push((rk - 1) >> i)
		}
	}
}

func (lst *LazySegTree) updateFrom(k int) {
	k >>= 1
	for k > 0 {
		lst.Dat[k] = lst.Op(lst.Dat[k<<1|0], lst.Dat[k<<1|1])
		k >>= 1
	}
}

func (lst *LazySegTree) updateFromRange(lk, rk int) {
	for i := 1; i <= lst.Log; i++ {
		if ((lk >> i) << i) != lk {
			lki := lk >> i
			lst.Dat[lki] = lst.Op(lst.Dat[lki<<1|0], lst.Dat[lki<<1|1])
		}
		if ((rk >> i) << i) != rk {
			rki := (rk - 1) >> i
			lst.Dat[rki] = lst.Op(lst.Dat[rki<<1|0], lst.Dat[rki<<1|1])
		}
	}
}

func (lst *LazySegTree) Set(p int, x S) {
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = x
	lst.updateFrom(p)
}

func (lst *LazySegTree) Get(p int) S {
	p += lst.N
	lst.pushTo(p)
	return lst.Dat[p]
}

func (lst *LazySegTree) AllProd() S {
	return lst.Dat[1]
}

func (lst *LazySegTree) Apply(p int, f F) {
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = lst.Mapping(f, lst.Dat[p])
	lst.updateFrom(p)
}

func (lst *LazySegTree) ApplyRange(l, r int, f F) {
	if l > r {
		panic(fmt.Sprintf("Invalid range: [%d, %d)", l, r))
	}
	l += lst.N
	r += lst.N
	lst.pushToRange(l, r)
	for l < r {
		if l&1 == 1 {
			lst.Dat[l] = lst.Mapping(f, lst.Dat[l])
			if l < lst.N {
				lst.Laz[l] = lst.Composition(f, lst.Laz[l])
			}
			l++
		}
		if r&1 == 1 {
			r--
			lst.Dat[r] = lst.Mapping(f, lst.Dat[r])
			if r < lst.N {
				lst.Laz[r] = lst.Composition(f, lst.Laz[r])
			}
		}
		l >>= 1
		r >>= 1
	}
	lst.updateFromRange(l, r)
}

func (lst *LazySegTree) MaxRight(l int, g func(S) bool) int {
	if !g(lst.E) {
		panic("Identity element must satisfy the condition.")
	}
	if l == lst.N {
		return lst.N
	}
	l += lst.N
	lst.pushTo(l)
	sum := lst.E
	for {
		l >>= bitLength(l) & -bitLength(l)
		if !g(lst.Op(sum, lst.Dat[l])) {
			for l < lst.N {
				lst.push(l)
				l <<= 1
				if g(lst.Op(sum, lst.Dat[l])) {
					sum = lst.Op(sum, lst.Dat[l])
					l++
				}
			}
			return l - lst.N
		}
		sum = lst.Op(sum, lst.Dat[l])
		l++
		if (l & -l) == l {
			break
		}
	}
	return lst.N
}

func (lst *LazySegTree) MinLeft(r int, g func(S) bool) int {
	if !g(lst.E) {
		panic("Identity element must satisfy the condition.")
	}
	if r == 0 {
		return 0
	}
	r += lst.N
	lst.pushTo(r - 1)
	sum := lst.E
	for {
		r--
		for r > 1 && r&1 == 1 {
			r >>= 1
		}
		if !g(lst.Op(lst.Dat[r], sum)) {
			for r < lst.N {
				lst.push(r)
				r = r<<1 | 1
				if g(lst.Op(lst.Dat[r], sum)) {
					sum = lst.Op(lst.Dat[r], sum)
					r--
				}
			}
			return r + 1 - lst.N
		}
		sum = lst.Op(lst.Dat[r], sum)
		if (r & -r) == r {
			break
		}
	}
	return 0
}

func bitLength(n int) int {
	var length int
	for n > 0 {
		length++
		n >>= 1
	}
	return length
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	N := readInt(in)
	Q := readInt(in)

	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}

	inv9 = modInv(9)

	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{tenmod[N-i-1], i, i}
	}

	lazySegTree := NewLazySegTreeFromArray(dat, (*S).op, S{0, (1<<31)>>1, -(1<<31)>>1}, (*S).mapFunc, (*F).composite, F{0, 0})

	for j := 0; j < Q; j++ {
		l := readInt(in) - 1
		r := readInt(in) - 1
		D := readInt64(in)
		lazySegTree.ApplyRange(l, r+1, F{D, N})
		fmt.Fprintln(out, lazySegTree.AllProd().sum)
	}
}

func readInt(in *bufio.Reader) int {
	n, _ := strconv.Atoi(readString(in))
	return n
}

func readInt64(in *bufio.Reader) int64 {
	n, _ := strconv.ParseInt(readString(in), 10, 64)
	return n
}

func readString(in *bufio.Reader) string {
	var buf []byte
	for {
		b, _ := in.ReadByte()
		if b == '\n' || b == ' ' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

// End of Code
