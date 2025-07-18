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

var S_E = S{0, int(^uint(0) >> 1) / 2, int(^uint(0) >> 1) / 2}

func (s1 S) op(s2 S) S {
	sum := s1.sum + s2.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	return S{sum, min(s1.l, s2.l), max(s1.r, s2.r)}
}

func (f F) mapS(s S) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1])
	if c < 0 {
		c += MOD2
	}
	return S{((f.D * c) % MOD2 * modInv(9)) % MOD2, s.l, s.r}
}

type F struct {
	D int64
	N int
}

var F_I = F{0, 0}

func (f F) composite(g F) F {
	return F{f.D, f.N}
}

type LazySegTree struct {
	MAX      int
	N        int
	Log      int
	Op       func(S, S) S
	E        S
	Mapping  func(F, S) S
	Composition func(F, F) F
	Id       F
	Dat      []S
	Laz      []F
}

func NewLazySegTree(n int, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	k := 1
	for k < n {
		k <<= 1
	}
	lst := &LazySegTree{
		MAX:      n,
		N:        k,
		Log:      bitLength(k),
		Op:       op,
		E:        e,
		Mapping:  mapping,
		Composition: composition,
		Id:       id,
		Dat:      make([]S, k<<1),
		Laz:      make([]F, k),
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
		lst.Dat[i] = lst.Op(lst.Dat[i<<1|0], lst.Dat[i<<1|1])
	}
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
			lst.push(rk >> i)
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

func (lst *LazySegTree) set(p int, x S) {
	lst.exclusiveRangeCheck(p)
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = x
	lst.updateFrom(p)
}

func (lst *LazySegTree) get(p int) S {
	lst.exclusiveRangeCheck(p)
	p += lst.N
	lst.pushTo(p)
	return lst.Dat[p]
}

func (lst *LazySegTree) allProd() S {
	return lst.Dat[1]
}

func (lst *LazySegTree) apply(p int, f F) {
	lst.exclusiveRangeCheck(p)
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = lst.Mapping(f, lst.Dat[p])
	lst.updateFrom(p)
}

func (lst *LazySegTree) applyRange(l, r int, f F) {
	if l > r {
		panic(fmt.Sprintf("Invalid range: [%d, %d)", l, r))
	}
	lst.inclusiveRangeCheck(l)
	lst.inclusiveRangeCheck(r)
	if l == r {
		return
	}
	l += lst.N
	r += lst.N
	lst.pushToRange(l, r)
	for l2, r2 := l, r; l2 < r2; {
		if (l2 & 1) == 1 {
			lst.Dat[l2] = lst.Mapping(f, lst.Dat[l2])
			if l2 < lst.N {
				lst.Laz[l2] = lst.Composition(f, lst.Laz[l2])
			}
			l2++
		}
		if (r2 & 1) == 1 {
			r2--
			lst.Dat[r2] = lst.Mapping(f, lst.Dat[r2])
			if r2 < lst.N {
				lst.Laz[r2] = lst.Composition(f, lst.Laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	lst.updateFromRange(l, r)
}

func (lst *LazySegTree) exclusiveRangeCheck(p int) {
	if p < 0 || p >= lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d).", p, 0, lst.MAX))
	}
}

func (lst *LazySegTree) inclusiveRangeCheck(p int) {
	if p < 0 || p > lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d].", p, 0, lst.MAX))
	}
}

func bitLength(n int) int {
	length := 0
	for n > 0 {
		n >>= 1
		length++
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
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	N, _ := strconv.Atoi(sc.Text())
	Q, _ := strconv.Atoi(sc.ScanText())
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{tenmod[N-i-1], i, i}
	}
	lst := NewLazySegTree(N, S{}.op, S_E, F{}.mapS, F{}.composite, F_I)
	lst.build(dat)
	for j := 0; j < Q; j++ {
		l, _ := strconv.Atoi(sc.ScanText())
		r, _ := strconv.Atoi(sc.ScanText())
		D, _ := strconv.ParseInt(sc.ScanText(), 10, 64)
		lst.applyRange(l-1, r, F{D, N})
		fmt.Println(lst.allProd().sum)
	}
}
// End of Code
