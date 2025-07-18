package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"math/bits"
)

const MOD2 = 998244353

var tenmod []int
var inv9 int
var S_E = S{sum: 0, l: math.MaxInt32 / 2, r: math.MinInt32 / 2}
var F_I = F{D: 0, N: 0}

type S struct {
	sum int
	l   int
	r   int
}

type F struct {
	D int
	N int
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

func opS(a, b S) S {
	sum := (a.sum + b.sum) % MOD2
	l := min(a.l, b.l)
	r := max(a.r, b.r)
	return S{sum: sum, l: l, r: r}
}

func mapS(f F, s S) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1]) % MOD2
	if c < 0 {
		c += MOD2
	}
	sum := (f.D * c) % MOD2
	sum = (sum * inv9) % MOD2
	return S{sum: sum, l: s.l, r: s.r}
}

func compositeF(f, g F) F {
	return F{D: f.D, N: f.N}
}

func modInv(x int) int {
	return modPow(x, MOD2-2)
}

func modPow(x, y int) int {
	res := 1
	x %= MOD2
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % MOD2
		}
		x = (x * x) % MOD2
		y /= 2
	}
	return res
}

type LazySegTree struct {
	N        int
	Log      int
	Dat      []S
	Laz      []F
	Op       func(a, b S) S
	E        S
	Mapping   func(f F, s S) S
	Composition func(f, g F) F
	Id       F
}

func NewSLazySegTree(data []S, op func(a, b S) S, e S, mapping func(f F, s S) S, composite func(f, g F) F, id F) *LazySegTree {
	n := len(data)
	tSize := 1
	for tSize < n {
		tSize <<= 1
	}
	logSize := bits.Len(uint(tSize)) - 1

	dat := make([]S, 2*tSize)
	for i := range dat {
		dat[i] = e
	}
	for i := 0; i < n; i++ {
		dat[tSize+i] = data[i]
	}
	for i := tSize - 1; i > 0; i-- {
		dat[i] = op(dat[2*i], dat[2*i+1])
	}

	laz := make([]F, 2*tSize)
	for i := range laz {
		laz[i] = id
	}

	return &LazySegTree{
		N: tSize,
		Log: logSize,
		Dat: dat,
		Laz: laz,
		Op: op,
		E: e,
		Mapping: mapping,
		Composition: composite,
		Id: id,
	}
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	left := 2 * k
	right := left + 1
	t.Dat[left] = t.Mapping(t.Laz[k], t.Dat[left])
	t.Dat[right] = t.Mapping(t.Laz[k], t.Dat[right])
	if left < t.N {
		t.Laz[left] = t.Composition(t.Laz[k], t.Laz[left])
		t.Laz[right] = t.Composition(t.Laz[k], t.Laz[right])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) pushTo(k int) {
	for i := t.Log; i > 0; i-- {
		node := k >> i
		t.push(node)
	}
}

func (t *LazySegTree) Apply(l, r int, f F) {
	if l >= r {
		return
	}
	l += t.N
	r += t.N
	for i := 1; i <= t.Log; i++ {
		if ((l >> i) << i) != l {
			t.push(l >> i)
		}
		if ((r >> i) << i) != r {
			t.push(r >> i)
		}
	}
	for l < r {
		if l%2 == 1 {
			t.Dat[l] = t.Mapping(f, t.Dat[l])
			if l < t.N {
				t.Laz[l] = t.Composition(f, t.Laz[l])
			}
			l++
		}
		if r%2 == 1 {
			r--
			t.Dat[r] = t.Mapping(f, t.Dat[r])
			if r < t.N {
				t.Laz[r] = t.Composition(f, t.Laz[r])
			}
		}
		l >>= 1
		r >>= 1
	}
}

func (t *LazySegTree) AllProd() S {
	return t.Dat[1]
}

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &Scanner{sc: sc}
}

func (s *Scanner) nextInt() int {
	s.sc.Scan()
	num, _ := strconv.Atoi(s.sc.Text())
	return num
}

func (s *Scanner) nextLong() int64 {
	s.sc.Scan()
	num, _ := strconv.ParseInt(s.sc.Text(), 10, 64)
	return num
}

func main() {
	sc := NewScanner(os.Stdin)
	N := sc.nextInt()
	Q := sc.nextInt()
	tenmod = make([]int, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	inv9 = modInv(9)

	data := make([]S, N)
	for i := 0; i < N; i++ {
		l, r := i, i
		sum := tenmod[N-i-1]
		data[i] = S{sum: sum, l: l, r: r}
	}

	t := NewSLazySegTree(data, opS, S_E, mapS, compositeF, F_I)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	for q := 0; q < Q; q++ {
		l := sc.nextInt() - 1
		r := sc.nextInt() - 1
		D := sc.nextLong()
		f := F{D: int(D), N: N}
		t.Apply(l, r+1, f)
		res := t.AllProd().sum
		fmt.Fprintln(out, res)
	}
}
// End of Code
