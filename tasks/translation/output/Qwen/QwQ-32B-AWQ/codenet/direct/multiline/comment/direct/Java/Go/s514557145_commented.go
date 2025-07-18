package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	MOD2 = 998244353
)

var inv9 int
var tenmod []int

func modInv(x int) int {
	return modPow(x, MOD2-2)
}

func modPow(x, y int) int {
	res := 1
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % MOD2
		}
		x = (x * x) % MOD2
		y /= 2
	}
	return res
}

func init() {
	inv9 = modInv(9)
}

type S struct {
	sum int
	l   int
	r   int
}

var S_E = S{0, math.MaxInt32/2, math.MinInt32/2}

func (s1 S) Op(s2 S) S {
	sum := (s1.sum + s2.sum) % MOD2
	if sum < 0 {
		sum += MOD2
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

type F struct {
	D int64
	N int
}

var F_I = F{0, 0}

func (f F) Composite(g F) F {
	return F{D: f.D, N: f.N}
}

func (f F) Map(s S) S {
	N := f.N
	a := tenmod[N-s.l]
	b := tenmod[N-s.r-1]
	c := (a - b) % MOD2
	if c < 0 {
		c += MOD2
	}
	c64 := int64(c)
	mod2Int64 := int64(MOD2)
	sum64 := (f.D * c64) % mod2Int64
	sum64 = (sum64 * int64(inv9)) % mod2Int64
	sum := int(sum64 % mod2Int64)
	return S{sum: sum, l: s.l, r: s.r}
}

type LazySegTree struct {
	N      int
	Log    int
	Dat    []S
	Laz    []F
}

func NewLazySegTree(data []S) *LazySegTree {
	n := len(data)
	t := &LazySegTree{
		N:   1,
		Log: 0,
	}
	for t.N < n {
		t.N <<= 1
		t.Log++
	}
	t.Dat = make([]S, 2*t.N)
	t.Laz = make([]F, t.N)
	for i := 0; i < t.N; i++ {
		if i < n {
			t.Dat[t.N+i] = data[i]
		} else {
			t.Dat[t.N+i] = S_E
		}
	}
	for i := t.N - 1; i > 0; i-- {
		t.Dat[i] = t.Dat[i<<1|0].Op(t.Dat[i<<1|1])
	}
	return t
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == F_I {
		return
	}
	lk := k << 1
	rk := k<<1 | 1
	t.Dat[lk] = t.Laz[k].Map(t.Dat[lk])
	t.Dat[rk] = t.Laz[k].Map(t.Dat[rk])
	if lk < t.N {
		t.Laz[lk] = t.Laz[k].Composite(t.Laz[lk])
	}
	if rk < t.N {
		t.Laz[rk] = t.Laz[k].Composite(t.Laz[rk])
	}
	t.Laz[k] = F_I
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

func (t *LazySegTree) updateFrom(l, r int) {
	for i := 1; i <= t.Log; i++ {
		if ((l >> i) << i) != l {
			lki := l >> i
			t.Dat[lki] = t.Dat[lki<<1|0].Op(t.Dat[lki<<1|1])
		}
		if ((r-1)>>i)<<i != r-1 {
			rki := (r - 1) >> i
			t.Dat[rki] = t.Dat[rki<<1|0].Op(t.Dat[rki<<1|1])
		}
	}
}

func (t *LazySegTree) Apply(a, b int, f F) {
	if a >= b {
		return
	}
	a += t.N
	b += t.N
	t.pushTo(a, b)
	l2, r2 := a, b
	for l2 < r2 {
		if l2&1 == 1 {
			t.Dat[l2] = f.Map(t.Dat[l2])
			if l2 < t.N {
				t.Laz[l2] = f.Composite(t.Laz[l2])
			}
			l2++
		}
		if r2&1 == 1 {
			r2--
			t.Dat[r2] = f.Map(t.Dat[r2])
			if r2 < t.N {
				t.Laz[r2] = f.Composite(t.Laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	t.updateFrom(a, b)
}

func (t *LazySegTree) AllProd() S {
	return t.Dat[1]
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextLong(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	N := nextInt(sc)
	Q := nextInt(sc)

	tenmod = make([]int, N+1)
	tenmod[0] = 1
	for i := 1; i <= N; i++ {
		tenmod[i] = (tenmod[i-1] * 10) % MOD2
	}

	data := make([]S, N)
	for i := 0; i < N; i++ {
		data[i] = S{
			sum: tenmod[N-i-1],
			l:   i,
			r:   i,
		}
	}

	t := NewLazySegTree(data)

	for q := 0; q < Q; q++ {
		l := nextInt(sc) - 1
		r := nextInt(sc) - 1
		D := nextLong(sc)
		f := F{D: D, N: N}
		t.Apply(l, r+1, f)
		fmt.Println(t.AllProd().sum)
	}
}
// End of Code
