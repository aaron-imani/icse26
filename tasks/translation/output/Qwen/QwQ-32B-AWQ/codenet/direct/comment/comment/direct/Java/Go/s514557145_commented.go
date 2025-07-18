package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

const MOD2 = 998244353
var inv9 int64
var tenmod []int64

type S struct {
	sum int64
	l   int
	r   int
}

var SE = S{
	sum: 0,
	l:   math.MaxInt32 / 2,
	r:   -math.MaxInt32 / 2,
}

type F struct {
	D int64
	N int
}

var IdF = F{0, 0}

func OpS(s1, s2 S) S {
	sum := (s1.sum + s2.sum) % MOD2
	if sum < 0 {
		sum += MOD2
	}
	newL := s1.l
	if s2.l < newL {
		newL = s2.l
	}
	newR := s1.r
	if s2.r > newR {
		newR = s2.r
	}
	return S{sum: sum, l: newL, r: newR}
}

func MapF(f F, s S) S {
	N := f.N
	l := s.l
	r := s.r

	c := (tenmod[N-l] - tenmod[N-r-1]) % MOD2
	if c < 0 {
		c += MOD2
	}
	newSum := (f.D * c) % MOD2
	newSum = (newSum * inv9) % MOD2
	return S{sum: newSum, l: l, r: r}
}

func CompositionF(f1, f2 F) F {
	return F{D: f1.D, N: f1.N}
}

type LazySegTree struct {
	N       int
	Log     int
	Dat     []S
	Laz     []F
	Op      func(S, S) S
	E       S
	Mapping func(F, S) S
	Composition func(F, F) F
	Id      F
}

func (t *LazySegTree) pushTo(l, r int) {
	for i := t.Log; i > 0; i-- {
		if ((l >> i) << i) != l {
			t.push(l >> i)
		}
		if ((r >> i) << i) != r {
			t.push((r - 1) >> i)
		}
	}
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	left := 2 * k
	right := 2*k + 1
	t.Dat[left] = t.Mapping(t.Laz[k], t.Dat[left])
	t.Dat[right] = t.Mapping(t.Laz[k], t.Dat[right])
	if left < t.N {
		t.Laz[left] = t.Composition(t.Laz[k], t.Laz[left])
	}
	if right < t.N {
		t.Laz[right] = t.Composition(t.Laz[k], t.Laz[right])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) apply(l, r int, f F) {
	if l > r {
		panic("Invalid range")
	}
	if l == r {
		return
	}

	l += t.N
	r += t.N
	t.pushTo(l, r)

	l2, r2 := l, r
	for l2 < r2 {
		if (l2 & 1) == 1 {
			t.Dat[l2] = t.Mapping(f, t.Dat[l2])
			if l2 < t.N {
				t.Laz[l2] = t.Composition(f, t.Laz[l2])
			}
			l2++
		}
		if (r2 & 1) == 1 {
			r2--
			t.Dat[r2] = t.Mapping(f, t.Dat[r2])
			if r2 < t.N {
				t.Laz[r2] = t.Composition(f, t.Laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
}

func (t *LazySegTree) allProd() S {
	return t.Dat[1]
}

func NewLazySegTree(data []S, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	n := len(data)
	t := &LazySegTree{
		N: 1,
		Log: 0,
		Op: op,
		E: e,
		Mapping: mapping,
		Composition: composition,
		Id: id,
	}
	for t.N < n {
		t.N <<= 1
	}
	t.Log = 0
	current := 1
	for current < t.N {
		t.Log++
		current <<= 1
	}
	t.Dat = make([]S, 2*t.N)
	for i := range t.Dat {
		t.Dat[i] = e
	}
	for i := 0; i < n; i++ {
		t.Dat[t.N+i] = data[i]
	}
	for i := t.N - 1; i > 0; i-- {
		t.Dat[i] = op(t.Dat[2*i], t.Dat[2*i+1])
	}
	t.Laz = make([]F, t.N)
	for i := range t.Laz {
		t.Laz[i] = id
	}
	return t
}

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

func modPow(x, y int64) int64 {
	res := int64(1)
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % MOD2
		}
		x = (x * x) % MOD2
		y /= 2
	}
	return res
}

func precomputeTenmod(n int) {
	tenmod = make([]int64, n+1)
	tenmod[0] = 1
	for i := 1; i <= n; i++ {
		tenmod[i] = (tenmod[i-1] * 10) % MOD2
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N, Q int
	fmt.Fscan(in, &N)
	fmt.Fcan(in, &Q)

	precomputeTenmod(N)
	inv9 = modInv(9)

	data := make([]S, N)
	for i := 0; i < N; i++ {
		pow := tenmod[N-i-1]
		data[i] = S{
			sum: pow,
			l: i,
			r: i,
		}
	}

	segTree := NewLazySegTree(data, OpS, SE, MapF, CompositionF, IdF)

	for q := 0; q < Q; q++ {
		var l, r int
		D := int64(0)
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &r)
		fmt.Fscan(in, &D)

		l--
		r--
		f := F{D: D, N: N}
		segTree.apply(l, r+1, f)
		res := segTree.allProd()
		fmt.Fprintln(out, res.sum)
	}
}

// End of Code
