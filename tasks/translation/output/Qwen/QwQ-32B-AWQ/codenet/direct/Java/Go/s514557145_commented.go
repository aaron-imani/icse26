package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const MOD2 = 998244353
var inv9 int64 = modInv(9)
var tenmod []int

type S struct {
	sum int
	l   int
	r   int
}

type F struct {
	D int64
	N int
}

type LazySegTree struct {
	N        int
	size     int
	dat      []S
	laz      []F
	op       func(a, b S) S
	e        S
	mapping  func(f F, s S) S
	compose  func(f, g F) F
	id       F
}

func NewLazySegTree(dat []S, op func(a, b S) S, e S, mapping func(f F, s S) S, compose func(f, g F) F, id F) *LazySegTree {
	n := len(dat)
	size := 1
	for size < n {
		size <<= 1
	}
	l := &LazySegTree{
		N:        size,
		size:     n,
		dat:      make([]S, 2*size),
		laz:      make([]F, size),
		op:       op,
		e:        e,
		mapping:  mapping,
		compose:  compose,
		id:       id,
	}
	for i := 0; i < n; i++ {
		l.dat[size+i] = dat[i]
	}
	for i := size - 1; i > 0; i-- {
		l.dat[i] = op(l.dat[2*i], l.dat[2*i+1])
	}
	for i := range l.laz {
		l.laz[i] = id
	}
	return l
}

func (l *LazySegTree) push(k int) {
	if l.laz[k] == l.id {
		return
	}
	lk := 2 * k
	rk := 2*k + 1
	l.dat[lk] = l.mapping(l.laz[k], l.dat[lk])
	l.dat[rk] = l.mapping(l.laz[k], l.dat[rk])
	if lk < l.N {
		l.laz[lk] = l.compose(l.laz[k], l.laz[lk])
	}
	if rk < l.N {
		l.laz[rk] = l.compose(l.laz[k], l.laz[rk])
	}
	l.laz[k] = l.id
}

func (l *LazySegTree) pushTo(k int) {
	h := bits.Len(uint(l.N)) - 1
	for i := h; i > 0; i-- {
		l.push(k >> i)
	}
}

func (l *LazySegTree) apply(a, b int, f F) {
	lNode := l.N + a
	rNode := l.N + b
	l2, r2 := lNode, rNode
	for l2 < r2 {
		if (l2 & 1) == 1 {
			l.dat[l2] = l.mapping(f, l.dat[l2])
			if l2 < l.N {
				l.laz[l2] = l.compose(f, l.laz[l2])
			}
			l2++
		}
		if (r2 & 杧 == 1 {
			r2--
			l.dat[r2] = l.mapping(f, l.dat[r2])
			if r2 < l.N {
				l.laz[r2] = l.compose(f, l.laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	l.updateFrom(lNode, rNode)
}

func (l *LazySegTree) updateFrom(lk, rk int) {
	h := bits.Len(uint(l.N)) - 1
	for i := 1; i <= h; i++ {
		mask := 1 << i
		if (lk & mask) != 0 {
			node := lk >> i
			l.dat[node] = l.op(l.dat[2*node], l.dat[2*node+1])
		}
		rkMinusOne := rk - 1
		if (rkMinusOne & mask) != 0 {
			node := rkMinusOne >> i
			l.dat[node] = l.op(l.dat[2*node], l.dat[2*node+1])
		}
	}
}

func (l *LazySegTree) allProd() S {
	return l.dat[1]
}

func modInv(x int) int64 {
	return modPow(int64(x), MOD2-2)
}

func modPow(x int64, y int) int64 {
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N, Q int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ = strconv.Atoi(scanner.Text())

	tenmod = make([]int, N+1)
	tenmod[0] = 1
	for i := 1; i <= N; i++ {
		tenmod[i] = (tenmod[i-1] * 10) % MOD2
	}

	dat := make([]S, N)
	for i := 0; i < N; i++ {
		powVal := tenmod[N-i-1]
		dat[i] = S{sum: powVal, l: i, r: i}
	}

	op := func(a, b S) S {
		sum := (a.sum + b.sum) % MOD2
		if sum < 0 {
			sum += MOD2
		}
		newL := min(a.l, b.l)
		newR := max(a.r, b.r)
		return S{sum: sum, l: newL, r: newR}
	}
	e := S{0, math.MaxInt, math.MinInt}
	mapping := func(f F, s S) S {
		term1 := tenmod[f.N - s.l]
		term2 := tenmod[f.N - s.r - 1]
		c := (term1 - term2) % MOD2
		if c < 0 {
			c += MOD2
		}
		dVal := (f.D * int64(c)) % MOD2
		sumVal := (dVal * inv9) % MOD2
		return S{sum: int(sumVal), l: s.l, r: s.r}
	}
	compose := func(f, g F) F {
		return F{D: f.D, N: f.N}
	}
	id := F{0, 0}

	segTree := NewLazySegTree(dat, op, e, mapping, compose, id)

	for q := 0; q < Q; q++ {
		var l, r int
		var D int64
		scanner.Scan()
		l, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		D, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		l--
		r--
		segTree.apply(l, r+1, F{D: D, N: N})
		fmt.Println(segTree.allProd().sum)
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

// End of Code
