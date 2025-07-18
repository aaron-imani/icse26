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

var tenmod []int64

type S struct {
	sum int64
	l   int
	r   int
}

func (s S) op(s2 S) S {
	sum := (s.sum + s2.sum) % MOD2
	return S{sum, min(s.l, s2.l), max(s.r, s2.r)}
}

func (s S) mapFunc(f F) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1]) % MOD2
	if c < 0 {
		c += MOD2
	}
	return S{(f.D * c * modInv(9)) % MOD2, s.l, s.r}
}

type F struct {
	D int64
	N int
}

func (f F) composite(g F) F {
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
	max  int
	n    int
	log  int
	op   func(S, S) S
	e    S
	mapping func(F, S) S
	composition func(F, F) F
	id   F
	dat  []S
	laz  []F
}

func NewLazySegTree(n int, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	k := 1
	for k < n {
		k <<= 1
	}
	return &LazySegTree{
		max:       n,
		n:         k,
		log:       bitLength(k),
		op:        op,
		e:         e,
		mapping:   mapping,
		composition: composition,
		id:        id,
		dat:       make([]S, k<<1),
		laz:       make([]F, k),
	}
}

func (t *LazySegTree) Build(dat []S) {
	copy(t.dat[t.n:], dat)
	for i := t.n - 1; i > 0; i-- {
		t.dat[i] = t.op(t.dat[i<<1|0], t.dat[i<<1|1])
	}
}

func (t *LazySegTree) Push(k int) {
	if t.laz[k] == t.id {
		return
	}
	t.dat[k<<1|0] = t.mapping(t.laz[k], t.dat[k<<1|0])
	t.dat[k<<1|1] = t.mapping(t.laz[k], t.dat[k<<1|1])
	if k < t.n {
		t.laz[k<<1|0] = t.composition(t.laz[k], t.laz[k<<1|0])
		t.laz[k<<1|1] = t.composition(t.laz[k], t.laz[k<<1|1])
	}
	t.laz[k] = t.id
}

func (t *LazySegTree) PushTo(k int) {
	for i := t.log; i > 0; i-- {
		t.Push(k >> i)
	}
}

func (t *LazySegTree) UpdateFrom(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		t.dat[k] = t.op(t.dat[k<<1|0], t.dat[k<<1|1])
	}
}

func (t *LazySegTree) Apply(p int, f F) {
	p += t.n
	t.PushTo(p)
	t.dat[p] = t.mapping(f, t.dat[p])
	t.UpdateFrom(p)
}

func (t *LazySegTree) AllProd() S {
	return t.dat[1]
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N, Q int
	fmt.Sscan(sc.Text(), &N)
	fmt.Sscan(sc.Text(), &Q)
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for i := 1; i <= N; i++ {
		tenmod[i] = (tenmod[i-1] * 10) % MOD2
	}
	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{0, i, i}
	}
	lazySegTree := NewLazySegTree(N, S{}.op, S{0, N/2, -N / 2}, S{}.mapFunc, F{}.composite, F{0, 0})
	lazySegTree.Build(dat)
	for i := 0; i < Q; i++ {
		l, r := 0, 0
		fmt.Sscan(sc.Text(), &l)
		fmt.Sscan(sc.Text(), &r)
		D := int64(0)
		fmt.Sscan(sc.Text(), &D)
		lazySegTree.Apply(l-1, F{D, N})
		fmt.Println(lazySegTree.AllProd().sum)
	}
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

func bitLength(n int) int {
	length := 0
	for n > 0 {
		n >>= 1
		length++
	}
	return length
}
// End of Code
