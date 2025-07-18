package main

import (
	"fmt"
	"math/big"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var tenmod []int64
var inv9 int64

type S struct {
	sum int64
	l   int
	r   int
}

type F struct {
	D int64
	N int
}

func main() {
	var N, Q int
	fmt.Scan(&N, &Q)
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{tenmod[N-i-1], i, i}
	}
	lazySegTree := NewLazySegTree(dat)
	for j := 0; j < Q; j++ {
		var l, r int
		var D int64
		fmt.Scan(&l, &r, &D)
		lazySegTree.Apply(l-1, r, F{D, N})
		fmt.Println(lazySegTree.AllProd().sum)
	}
}

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

func modPow(x, y int64) int64 {
	z := big.NewInt(1)
	for y > 0 {
		if y%2 == 0 {
			x = (x * x) % MOD2
			y /= 2
		} else {
			z = z.Mul(z, big.NewInt(x)).Mod(z, big.NewInt(MOD2))
			y--
		}
	}
	return z.Int64()
}

type LazySegTree struct {
	N     int
	Log   int
	Dat   []S
	Laz   []F
	Op    func(S, S) S
	E     S
	Mapping func(F, S) S
	Composition func(F, F) F
	Id    F
}

func NewLazySegTree(dat []S) *LazySegTree {
	N := len(dat)
	Log := 1
	for 1<<Log < N {
		Log++
	}
	N = 1 << Log
	Dat := make([]S, 2*N)
	Laz := make([]F, N)
	for i := 0; i < len(dat); i++ {
		Dat[i+N] = dat[i]
	}
	for i := N - 1; i > 0; i-- {
		Dat[i] = S{Dat[i<<1|0].sum + Dat[i<<1|1].sum, 0, 0}
	}
	return &LazySegTree{
		N:     N,
		Log:   Log,
		Dat:   Dat,
		Laz:   Laz,
		Op:    func(s1, s2 S) S { return S{s1.sum + s2.sum, 0, 0} },
		E:     S{0, 0, 0},
		Mapping: func(f F, s S) S {
			c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1])
			if c < 0 {
				c += MOD2
			}
			return S{((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r}
		},
		Composition: func(f, g F) F { return F{f.D, f.N} },
		Id:          F{0, 0},
	}
}

func (t *LazySegTree) Apply(l, r int, f F) {
	if l > r {
		return
	}
	l += t.N
	r += t.N
	for i := t.Log; i > 0; i-- {
		if (l >> i) << i != l {
			t.push(l >> i)
		}
		if (r >> i) << i != r {
			t.push((r - 1) >> i)
		}
	}
	l2, r2 := l, r
	for l2 < r2 {
		if l2&1 == 1 {
			t.Mapping(f, t.Dat[l2])
			if l2 < t.N {
				t.Laz[l2] = t.Composition(f, t.Laz[l2])
			}
			l2++
		}
		if r2&1 == 1 {
			r2--
			t.Mapping(f, t.Dat[r2])
			if r2 < t.N {
				t.Laz[r2] = t.Composition(f, t.Laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	for i := t.Log; i > 0; i-- {
		if (l >> i) << i != l {
			t.updateFrom(l >> i)
		}
		if (r >> i) << i != r {
			t.updateFrom((r - 1) >> i)
		}
	}
}

func (t *LazySegTree) AllProd() S {
	return t.Dat[1]
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	t.Mapping(t.Laz[k], t.Dat[k<<1|0])
	t.Mapping(t.Laz[k], t.Dat[k<<1|1])
	if k < t.N {
		t.Laz[k<<1|0] = t.Composition(t.Laz[k], t.Laz[k<<1|0])
		t.Laz[k<<1|1] = t.Composition(t.Laz[k], t.Laz[k<<1|1])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) updateFrom(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		t.Dat[k] = t.Op(t.Dat[k<<1|0], t.Dat[k<<1|1])
	}
}
// End of Code
