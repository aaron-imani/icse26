package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
	"strconv"
)

const (
	MOD2 = 998244353
)

type S struct {
	sum int64
	l   int
	r   int
}

var E_S = S{0, math.MaxInt, math.MinInt}

type F struct {
	D int64
	N int
}

var Id_F = F{0, 0}

func opS(s1, s2 S) S {
	sum := s1.sum + s2.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	l := min(s1.l, s2.l)
	r := max(s1.r, s2.r)
	return S{sum, l, r}
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

func mapFS(f F, s S) S {
	N := f.N
	term1 := tenmod[N-s.l]
	term2 := tenmod[N-s.r-1]
	var c int64
	if term1 >= term2 {
		c = term1 - term2
	} else {
		c = term1 + (MOD2 - term2)
	}
	newSum := (f.D * c) % MOD2
	newSum = (newSum * inv9) % MOD2
	return S{newSum, s.l, s.r}
}

func compositeF(f, g F) F {
	return F{D: f.D, N: f.N}
}

var tenmod []int64
var inv9 int64

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

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

type LazySegTree struct {
	dat       []S
	laz       []F
	N         int
	size      int
	Log       int
	op        func(S, S) S
	e         S
	mapping   func(F, S) S
	composition func(F, F) F
	id        F
}

func NewLazySegTree(data []S, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	n := len(data)
	var size int
	for size = 1; size < n; size <<= 1 {
	}
	Log := bits.TrailingZeros(uint(size))
	dat := make([]S, 2*size)
	for i := range dat {
		dat[i] = e
	}
	for i := 0; i < n; i++ {
		dat[size+i] = data[i]
	}
	for i := size - 1; i > 0; i-- {
		dat[i] = op(dat[2*i], dat[2*i+1])
	}
	laz := make([]F, size)
	for i := range laz {
		laz[i] = id
	}
	return &LazySegTree{
		dat:       dat,
		laz:       laz,
		N:         n,
		size:      size,
		Log:       Log,
		op:        op,
		e:         e,
		mapping:   mapping,
		composition: composition,
		id:        id,
	}
}

func (t *LazySegTree) push(k int) {
	if t.laz[k] == t.id {
		return
	}
	left := 2 * k
	right := left + 1
	t.dat[left] = t.mapping(t.laz[k], t.dat[left])
	t.dat[right] = t.mapping(t.laz[k], t.dat[right])
	if left < t.size {
		t.laz[left] = t.composition(t.laz[k], t.laz[left])
	}
	if right < t.size {
		t.laz[right] = t.composition(t.laz[k], t.laz[right])
	}
	t.laz[k] = t.id
}

func (t *LazySegTree) pushTo(l, r int) {
	for i := t.Log; i > 0; i-- {
		level := 1 << (i - 1)
		k := l >> i
		if (k << i) != l {
			t.push(k)
		}
		k = r >> i
		if (k << i) != r {
			t.push(k)
		}
	}
}

func (t *LazySegTree) Apply(l, r int, f F) {
	if l > r {
		return
	}
	l += t.size
	r += t.size
	t.pushTo(l, r)
	l2, r2 := l, r
	for l2 < r2 {
		if (l2 & 1) == 1 {
			t.push(l2)
			t.dat[l2] = t.mapping(f, t.dat[l2])
			if l2 < t.size {
				t.laz[l2] = t.composition(f, t.laz[l2])
			}
			l2++
		}
		if (r2 & 1) == 1 {
			r2--
			t.push(r2)
			t.dat[r2] = t.mapping(f, t.dat[r2])
			if r2 < t.size {
				t.laz[r2] = t.composition(f, t.laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	t.updateFrom(l, r)
}

func (t *LazySegTree) updateFrom(l, r int) {
	for i := 1; i <= t.Log; i++ {
		lk := l >> i
		if (lk << i) != l {
			k := lk
			t.dat[k] = t.op(t.dat[2*k], t.dat[2*k+1])
		}
		rk := (r - 1) >> i
		if (rk << i) != (r - 1) {
			k := rk
			t.dat[k] = t.op(t.dat[2*k], t.dat[2*k+1])
		}
	}
}

func (t *LazySegTree) AllProd() S {
	return t.dat[1]
}

type InputReader struct {
	sc *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &InputReader{sc: sc}
}

func (sc *InputReader) readInt() int {
	sc.sc.Scan()
	n, _ := strconv.Atoi(sc.sc.Text())
	return n
}

func (sc *InputReader) readLong() int64 {
	sc.sc.Scan()
	n, _ := strconv.ParseInt(sc.sc.Text(), 10, 64)
	return n
}

func main() {
	sc := NewInputReader(os.Stdin)
	N := sc.readInt()
	Q := sc.readInt()

	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	inv9 = modInv(9)

	data := make([]S, N)
	for i := 0; i < N; i++ {
		pow := tenmod[N-i-1]
		data[i] = S{sum: pow, l: i, r: i}
	}

	segTree := NewLazySegTree(data, opS, E_S, mapFS, compositeF, Id_F)

	for q := 0; q < Q; q++ {
		l := sc.readInt() - 1
		r := sc.readInt() - 1
		D := sc.readLong()
		segTree.Apply(l, r+1, F{D, N})
		sum := segTree.AllProd().sum
		fmt.Println(sum)
	}
}

// End of Code
