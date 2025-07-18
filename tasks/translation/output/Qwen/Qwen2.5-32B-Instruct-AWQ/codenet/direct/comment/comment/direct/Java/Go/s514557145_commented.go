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

func (f F) mapFunc(s S) S {
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
	log := bitLength(k)
	dat := make([]S, k<<1)
	laz := make([]F, k)
	for i := range dat {
		dat[i] = e
	}
	for i := range laz {
		laz[i] = id
	}
	return &LazySegTree{
		max:       n,
		n:         k,
		log:       log,
		op:        op,
		e:         e,
		mapping:   mapping,
		composition: composition,
		id:        id,
		dat:       dat,
		laz:       laz,
	}
}

func (t *LazySegTree) build(dat []S) {
	copy(t.dat[t.n:], dat)
	for i := t.n - 1; i > 0; i-- {
		t.dat[i] = t.op(t.dat[i<<1|0], t.dat[i<<1|1])
	}
}

func (t *LazySegTree) push(k int) {
	if t.laz[k] == t.id {
		return
	}
	t.dat[k<<1|0] = t.mapping(t.laz[k], t.dat[k<<1|0])
	t.dat[k<<1|1] = t.mapping(t.laz[k], t.dat[k<<1|1])
	if k<<1|0 < t.n {
		t.laz[k<<1|0] = t.composition(t.laz[k], t.laz[k<<1|0])
	}
	if k<<1|1 < t.n {
		t.laz[k<<1|1] = t.composition(t.laz[k], t.laz[k<<1|1])
	}
	t.laz[k] = t.id
}

func (t *LazySegTree) pushTo(k int) {
	for i := t.log; i > 0; i-- {
		t.push(k >> i)
	}
}

func (t *LazySegTree) pushToRange(l, r int) {
	for i := t.log; i > 0; i-- {
		if ((l >> i) << i) != l {
			t.push(l >> i)
		}
		if ((r >> i) << i) != r {
			t.push(r >> i)
		}
	}
}

func (t *LazySegTree) updateFrom(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		t.dat[k] = t.op(t.dat[k<<1|0], t.dat[k<<1|1])
	}
}

func (t *LazySegTree) updateFromRange(l, r int) {
	for i := 1; i <= t.log; i++ {
		if ((l >> i) << i) != l {
			t.dat[l>>i] = t.op(t.dat[l>>i<<1|0], t.dat[l>>i<<1|1])
		}
		if ((r >> i) << i) != r {
			t.dat[(r-1)>>i] = t.op(t.dat[(r-1)>>i<<1|0], t.dat[(r-1)>>i<<1|1])
		}
	}
}

func (t *LazySegTree) set(p int, x S) {
	p += t.n
	t.pushTo(p)
	t.dat[p] = x
	t.updateFrom(p)
}

func (t *LazySegTree) get(p int) S {
	p += t.n
	t.pushTo(p)
	return t.dat[p]
}

func (t *LazySegTree) allProd() S {
	return t.dat[1]
}

func (t *LazySegTree) apply(p int, f F) {
	p += t.n
	t.pushTo(p)
	t.dat[p] = t.mapping(f, t.dat[p])
	t.updateFrom(p)
}

func (t *LazySegTree) applyRange(l, r int, f F) {
	if l > r {
		panic(fmt.Sprintf("Invalid range: [%d, %d)", l, r))
	}
	if l == r {
		return
	}
	l += t.n
	r += t.n
	t.pushToRange(l, r)
	for l < r {
		if l&1 == 1 {
			t.dat[l] = t.mapping(f, t.dat[l])
			if l < t.n {
				t.laz[l] = t.composition(f, t.laz[l])
			}
			l++
		}
		if r&1 == 1 {
			r--
			t.dat[r] = t.mapping(f, t.dat[r])
			if r < t.n {
				t.laz[r] = t.composition(f, t.laz[r])
			}
		}
		l >>= 1
		r >>= 1
	}
	t.updateFromRange(l, r)
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ := strconv.Atoi(scanner.Text())

	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}

	dat := make([]S, N)
	for i := range dat {
		dat[i] = S{tenmod[N-i-1], i, i}
	}

	lazySegTree := NewLazySegTree(N, S{}.op, S{0, N / 2, -N / 2}, F{}.mapFunc, F{}.composite, F{0, 0})
	lazySegTree.build(dat)

	for j := 0; j < Q; j++ {
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		D, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		lazySegTree.applyRange(l-1, r, F{D, N})
		fmt.Println(lazySegTree.allProd().sum)
	}
}

// End of Code
