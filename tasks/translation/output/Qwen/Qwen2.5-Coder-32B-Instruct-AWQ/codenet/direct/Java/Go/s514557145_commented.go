package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var tenmod []int64

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

type S struct {
	sum int64
	l   int
	r   int
}

func (s S) op(s2 S) S {
	sum := s.sum + s2.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	return S{sum, min(s.l, s2.l), max(s.r, s2.r)}
}

func (s S) mapF(f F) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1])
	if c < 0 {
		c += MOD2
	}
	inv9 := modInv(9)
	return S{((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r}
}

type F struct {
	D int64
	N int
}

func (f F) composite(f2 F) F {
	return F{f.D, f.N}
}

var (
	S_E = S{0, (1 << 31) / 2, -(1 << 31) / 2}
	F_I = F{0, 0}
)

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
		Log:         32 - bitsLeadingZeros(uint(k)),
		Op:          op,
		E:           e,
		Mapping:     mapping,
		Composition: composition,
		Id:          id,
		Dat:         make([]S, k*2),
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

func (lst *LazySegTree) build(dat []S) {
	l := len(dat)
	copy(lst.Dat[lst.N:], dat)
	for i := lst.N - 1; i > 0; i-- {
		lst.Dat[i] = lst.Op(lst.Dat[i<<1], lst.Dat[i<<1|1])
	}
}

func (lst *LazySegTree) push(k int) {
	if lst.Laz[k] == F_I {
		return
	}
	lk, rk := k<<1, k<<1|1
	lst.Dat[lk] = lst.Mapping(lst.Laz[k], lst.Dat[lk])
	lst.Dat[rk] = lst.Mapping(lst.Laz[k], lst.Dat[rk])
	if lk < lst.N {
		lst.Laz[lk] = lst.Composition(lst.Laz[k], lst.Laz[lk])
	}
	if rk < lst.N {
		lst.Laz[rk] = lst.Composition(lst.Laz[k], lst.Laz[rk])
	}
	lst.Laz[k] = F_I
}

func (lst *LazySegTree) pushTo(k int) {
	for i := lst.Log; i > 0; i-- {
		lst.push(k >> i)
	}
}

func (lst *LazySegTree) pushTo(lk, rk int) {
	for i := lst.Log; i > 0; i-- {
		if ((lk >> i) << i) != lk {
			lst.push(lk >> i)
		}
		if ((rk >> i) << i) != rk {
			lst.push(rk >> i)
		}
	}
}

func (lst *LazySegTree) updateFrom(k int) {
	k >>= 1
	for k > 0 {
		lst.Dat[k] = lst.Op(lst.Dat[k<<1], lst.Dat[k<<1|1])
		k >>= 1
	}
}

func (lst *LazySegTree) updateFrom(lk, rk int) {
	for i := 1; i <= lst.Log; i++ {
		if ((lk >> i) << i) != lk {
			lki := lk >> i
			lst.Dat[lki] = lst.Op(lst.Dat[lki<<1], lst.Dat[lki<<1|1])
		}
		if ((rk >> i) << i) != rk {
			rki := (rk - 1) >> i
			lst.Dat[rki] = lst.Op(lst.Dat[rki<<1], lst.Dat[rki<<1|1])
		}
	}
}

func (lst *LazySegTree) set(p int, x S) {
	if p < 0 || p >= lst.N {
		panic("Index out of range")
	}
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = x
	lst.updateFrom(p)
}

func (lst *LazySegTree) get(p int) S {
	if p < 0 || p >= lst.N {
		panic("Index out of range")
	}
	p += lst.N
	lst.pushTo(p)
	return lst.Dat[p]
}

func (lst *LazySegTree) allProd() S {
	return lst.Dat[1]
}

func (lst *LazySegTree) apply(p int, f F) {
	if p < 0 || p >= lst.N {
		panic("Index out of range")
	}
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = lst.Mapping(f, lst.Dat[p])
	lst.updateFrom(p)
}

func (lst *LazySegTree) applyRange(l, r int, f F) {
	if l > r {
		panic("Invalid range")
	}
	if l < 0 || r > lst.N {
		panic("Index out of range")
	}
	if l == r {
		return
	}
	l += lst.N
	r += lst.N
	lst.pushTo(l, r)
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
	lst.updateFrom(l, r)
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

func bitsLeadingZeros(x uint) int {
	if x == 0 {
		return 32
	}
	return 31 - bitsTrailingZeros(x)
}

func bitsTrailingZeros(x uint) int {
	if x == 0 {
		return 32
	}
	var n int
	for x&1 == 0 {
		n++
		x >>= 1
	}
	return n
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

	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{tenmod[N-i-1], i, i}
	}

	lazySegTree := NewLazySegTree(N, S.op, S_E, S.mapF, F.composite, F_I)
	lazySegTree.build(dat)

	for j := 0; j < Q; j++ {
		l := readInt(in) - 1
		r := readInt(in) - 1
		D := readInt64(in)
		lazySegTree.applyRange(l, r+1, F{D, N})
		fmt.Fprintln(out, lazySegTree.allProd().sum)
	}
}

func readInt(in *bufio.Reader) int {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	v, _ := strconv.Atoi(line)
	return v
}

func readInt64(in *bufio.Reader) int64 {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	v, _ := strconv.ParseInt(line, 10, 64)
	return v
}

// End of Code
