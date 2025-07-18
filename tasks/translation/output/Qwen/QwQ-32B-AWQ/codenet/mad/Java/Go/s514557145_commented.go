package main

import (
	"bufio"
	"bytes"
	"io"
	"math"
	"os"
	"strconv"
	"math/bits"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var (
	tenmod []int64
	inv9   int64 = modInv(9)
)

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

type S struct {
	sum int64
	l   int
	r   int
}

var S_E = S{0, math.MaxInt32 / 2, math.MinInt32 / 2}

func opS(a, b S) S {
	sum := a.sum + b.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	return S{
		sum: sum,
		l:   min(a.l, b.l),
		r:   max(a.r, b.r),
	}
}

type F struct {
	D int64
	N int
}

var F_I = F{0, 0}

func compositeF(f, g F) F {
	return F{D: f.D + g.D, N: f.N}
}

func mapF(f F, s S) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1]) % MOD2
	if c < 0 {
		c += MOD2
	}
	sum := (f.D * c) % MOD2
	sum = (sum * inv9) % MOD2
	return S{sum: sum, l: s.l, r: s.r}
}

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

func modPow(x, y int64) int64 {
	z := int64(1)
	for y > 0 {
		if y%2 == 1 {
			z = (z * x) % MOD2
		}
		x = (x * x) % MOD2
		y /= 2
	}
	return z
}

type InputReader struct {
	sc *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &InputReader{sc: sc}
}

func (r *InputReader) Next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *InputReader) NextInt() int {
	s := r.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (r *InputReader) NextLong() int64 {
	s := r.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

type LazySegTree struct {
	MAX  int
	N    int
	Log  int
	Dat  []S
	Laz  []F
	Op   func(a, b S) S
	E    S
	Map   func(f F, s S) S
	Compose func(a, b F) F
	Id    F
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	left := 2 * k
	right := left + 1
	t.Dat[left] = t.Map(t.Laz[k], t.Dat[left])
	t.Dat[right] = t.Map(t.Laz[k], t.Dat[right])
	if left < t.N {
		t.Laz[left] = t.Compose(t.Laz[k], t.Laz[left])
	}
	if right < t.N {
		t.Laz[right] = t.Compose(t.Laz[k], t.Laz[right])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) pushTo(k int) {
	for i := t.Log; i > 0; i-- {
		t.push(k >> i)
	}
}

func (t *LazySegTree) pushToRange(l, r int) {
	for i := t.Log; i > 0; i-- {
		if (l >> i) << i != l {
			t.push(l >> i)
		}
		if (r >> i) << i != r {
			t.push((r - 1) >> i)
		}
	}
}

func (t *LazySegTree) updateFrom(lk, rk int) {
	for i := 1; i <= t.Log; i++ {
		if ((lk >> i) << i) != lk {
			lki := lk >> i
			t.Dat[lki] = t.Op(t.Dat[2*lki], t.Dat[2*lki+1])
		}
		if ((rk >> i) << i) != rk {
			rki := (rk - 1) >> i
			t.Dat[rki] = t.Op(t.Dat[2*rki], t.Dat[2*rki+1])
		}
	}
}

func NewLazySegTree(dat []S, op func(a, b S) S, e S, mapFn func(f F, s S) S, compose func(a, b F) F, id F) *LazySegTree {
	n := len(dat)
	max := n
	k := 1
	for k < n {
		k <<= 1
	}
	log := bits.Len(uint(k)) - 1
	N := k
	Dat := make([]S, 2*N)
	Laz := make([]F, N)
	copy(Dat[N:], dat)
	for i := N - 1; i > 0; i-- {
		Dat[i] = op(Dat[2*i], Dat[2*i+1])
	}
	for i := range Laz {
		Laz[i] = id
	}
	return &LazySegTree{
		MAX:   max,
		N:     N,
		Log:   log,
		Dat:   Dat,
		Laz:   Laz,
		Op:    op,
		E:     e,
		Map:   mapFn,
		Compose: compose,
		Id:    id,
	}
}

func (t *LazySegTree) Apply(l, r int, f F) {
	if l > r {
		panic("Invalid range")
	}
	if l == r {
		return
	}
	l += t.N
	r += t.N
	t.pushToRange(l, r)
	for l < r {
		if l%2 == 1 {
			t.Dat[l] = t.Map(f, t.Dat[l])
			if l < t.N {
				t.Laz[l] = t.Compose(f, t.Laz[l])
			}
			l++
		}
		if r%2 == 奏 {
			r--
			t.Dat[r] = t.Map(f, t.Dat[r])
			if r < t.N {
				t.Laz[r] = t.Compose(f, t.Laz[r])
			}
		}
		l >>= 1
		r >>= 1
	}
	t.updateFrom(l, r)
}

func (t *LazySegTree) AllProd() S {
	return t.Dat[1]
}

func main() {
	sc := NewInputReader(os.Stdin)
	N := sc.NextInt()
	Q := sc.NextInt()
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	dat := make([]S, N)
	for i := 0; i < N; i++ {
		dat[i] = S{
			sum: tenmod[N-i-1],
			l:   i,
			r:   i,
		}
	}
	lazySegTree := NewLazySegTree(dat, opS, S_E, mapF, compositeF, F_I)
	buf := new(bytes.Buffer)
	out := bufio.NewWriter(buf)
	for j := 0; j < Q; j++ {
		l := sc.NextInt() - 1
		r := sc.NextInt() - 1
		D := sc.NextLong()
		lazySegTree.Apply(l, r+1, F{D: D, N: N})
		sum := lazySegTree.AllProd().sum
		fmt.Fprintln(out, sum)
	}
	out.Flush()
	buf.WriteTo(os.Stdout)
}
// End of Code
