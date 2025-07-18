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
	sum := (s.sum + s2.sum) % MOD2
	return S{sum, min(s.l, s2.l), max(s.r, s2.r)}
}

func (f F) mapFunc(s S) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1]) % MOD2
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

type LazySegTree struct {
	MAX        int
	N          int
	Log        int
	Op         func(S, S) S
	E          S
	Mapping    func(F, S) S
	Composition func(F, F) F
	Id         F
	Dat        []S
	Laz        []F
}

func NewLazySegTree(n int, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	tree := &LazySegTree{
		MAX:        n,
		N:          1,
		Log:        0,
		Op:         op,
		E:          e,
		Mapping:    mapping,
		Composition: composition,
		Id:         id,
		Dat:        make([]S, n<<1),
		Laz:        make([]F, n),
	}
	for tree.N < n {
		tree.N <<= 1
	}
	tree.Log = int(math.Log2(float64(tree.N)))
	for i := range tree.Dat {
		tree.Dat[i] = e
	}
	for i := range tree.Laz {
		tree.Laz[i] = id
	}
	return tree
}

func (t *LazySegTree) build(dat []S) {
	l := len(dat)
	copy(t.Dat[t.N:], dat)
	for i := t.N - 1; i > 0; i-- {
		t.Dat[i] = t.Op(t.Dat[i<<1|0], t.Dat[i<<1|1])
	}
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	lk, rk := k<<1|0, k<<1|1
	t.Dat[lk] = t.Mapping(t.Laz[k], t.Dat[lk])
	t.Dat[rk] = t.Mapping(t.Laz[k], t.Dat[rk])
	if lk < t.N {
		t.Laz[lk] = t.Composition(t.Laz[k], t.Laz[lk])
	}
	if rk < t.N {
		t.Laz[rk] = t.Composition(t.Laz[k], t.Laz[rk])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) pushTo(k int) {
	for i := t.Log; i > 0; i-- {
		t.push(k >> i)
	}
}

func (t *LazySegTree) pushToRange(lk, rk int) {
	for i := t.Log; i > 0; i-- {
		if ((lk >> i) << i) != lk {
			t.push(lk >> i)
		}
		if ((rk >> i) << i) != rk {
			t.push(rk >> i)
		}
	}
}

func (t *LazySegTree) updateFrom(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		t.Dat[k] = t.Op(t.Dat[k<<1|0], t.Dat[k<<1|1])
	}
}

func (t *LazySegTree) updateFromRange(lk, rk int) {
	for i := 1; i <= t.Log; i++ {
		if ((lk >> i) << i) != lk {
			lki := lk >> i
			t.Dat[lki] = t.Op(t.Dat[lki<<1|0], t.Dat[lki<<1|1])
		}
		if ((rk >> i) << i) != rk {
			rki := (rk - 1) >> i
			t.Dat[rki] = t.Op(t.Dat[rki<<1|0], t.Dat[rki<<1|1])
		}
	}
}

func (t *LazySegTree) set(p int, x S) {
	t.exclusiveRangeCheck(p)
	p += t.N
	t.pushTo(p)
	t.Dat[p] = x
	t.updateFrom(p)
}

func (t *LazySegTree) get(p int) S {
	t.exclusiveRangeCheck(p)
	p += t.N
	t.pushTo(p)
	return t.Dat[p]
}

func (t *LazySegTree) allProd() S {
	return t.Dat[1]
}

func (t *LazySegTree) apply(p int, f F) {
	t.exclusiveRangeCheck(p)
	p += t.N
	t.pushTo(p)
	t.Dat[p] = t.Mapping(f, t.Dat[p])
	t.updateFrom(p)
}

func (t *LazySegTree) applyRange(l, r int, f F) {
	if l > r {
		panic(fmt.Sprintf("Invalid range: [%d, %d)", l, r))
	}
	t.inclusiveRangeCheck(l)
	t.inclusiveRangeCheck(r)
	if l == r {
		return
	}
	l += t.N
	r += t.N
	t.pushToRange(l, r)
	for l2, r2 := l, r; l2 < r2; {
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
	t.updateFromRange(l, r)
}

func (t *LazySegTree) exclusiveRangeCheck(p int) {
	if p < 0 || p >= t.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d).", p, 0, t.MAX))
	}
}

func (t *LazySegTree) inclusiveRangeCheck(p int) {
	if p < 0 || p > t.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d].", p, 0, t.MAX))
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

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	N, _ := strconv.Atoi(sc.Text())
	Q, _ := strconv.Atoi(sc.Text())
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{tenmod[N-i-1], i, i}
	}
	lazySegTree := NewLazySegTree(N, S{}.op, S{0, math.MaxInt32 / 2, math.MinInt32 / 2}, F{}.mapFunc, F{}.composite, F{0, 0})
	lazySegTree.build(dat)
	for j := 0; j < Q; j++ {
		l, _ := strconv.Atoi(sc.Text())
		r, _ := strconv.Atoi(sc.Text())
		D, _ := strconv.ParseInt(sc.Text(), 10, 64)
		lazySegTree.applyRange(l-1, r, F{D, N})
		fmt.Println(lazySegTree.allProd().sum)
	}
}
// End of Code
