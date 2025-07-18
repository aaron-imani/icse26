package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

const (
	MOD2 = 998244353
)

var tenmod []int
var S_E = S{0, math.MaxInt, math.MinInt}

type S struct {
	Sum int
	L   int
	R   int
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

func op(a, b S) S {
	sum := (a.Sum + b.Sum) % MOD2
	if sum < 0 {
		sum += MOD2
	}
	l := min(a.L, b.L)
	r := max(a.R, b.R)
	return S{sum, l, r}
}

var inv9 int

func mapS(f F, s S) S {
	N := f.N
	var c int
	c = (tenmod[N-s.L] - tenmod[N-s.R-1]) % MOD2
	if c < 0 {
		c += MOD2
	}
	sum := (f.D * c) % MOD2
	sum = (sum * inv9) % MOD2
	return S{sum, s.L, s.R}
}

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

func compositeF(f, g F) F {
	return F{D: f.D, N: f.N}
}

type LazySegTree struct {
	N    int
	Log  int
	dat  []S
	laz  []F
	Op   func(S, S) S
	E    S
	Map   func(F, S) S
	Compose func(F, F) F
	Id   F
}

func NewLazySegTree(dat []S, opFunc func(S, S) S, e S, mapFunc func(F, S) S, composeFunc func(F, F) F, id F) *LazySegTree {
	n := len(dat)
	N := 1
	for N < n {
		N <<= 1
	}
	Log := 0
	for (1 << Log) < N {
		Log++
	}
	newDat := make([]S, 2*N)
	copy(newDat[N:], dat)
	for i := N - 1; i > 0; i-- {
		newDat[i] = opFunc(newDat[2*i], newDat[2*i+1])
	}
	newLaz := make([]F, N)
	for i := range newLaz {
		newLaz[i] = id
	}
	return &LazySegTree{
		N:    N,
		Log:  Log,
		dat:  newDat,
		laz:  newLaz,
		Op:   opFunc,
		E:    e,
		Map:  mapFunc,
		Compose: composeFunc,
		Id:   id,
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
	t.pushTo(l, r)
	for l2, r2 := l, r; l2 < r2; {
		if (l2 & 1) == 1 {
			t.dat[l2] = t.Map(f, t.dat[l2])
			if l2 < t.N {
				t.laz[l2] = t.Compose(f, t.laz[l2])
			}
			l2++
		}
		if (r2 & 1) == 1 {
			r2--
			t.dat[r2] = t.Map(f, t.dat[r2])
			if r2 < t.N {
				t.laz[r2] = t.Compose(f, t.laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	t.updateFrom(l, r)
}

func (t *LazySegTree) pushTo(lk, rk int) {
	for i := t.Log; i > 0; i-- {
		nodeL := lk >> i
		if (nodeL << i) != lk {
			t.push(nodeL)
		}
		nodeR := rk >> i
		if (nodeR << i) != rk {
			t.push(nodeR)
		}
	}
}

func (t *LazySegTree) push(k int) {
	if t.laz[k] == t.Id {
		return
	}
	left := 2 * k
	right := left + 1
	t.dat[left] = t.Map(t.laz[k], t.dat[left])
	t.dat[right] = t.Map(t.laz[k], t.dat[right])
	if left < t.N {
		t.laz[left] = t.Compose(t.laz[k], t.laz[left])
	}
	if right < t.N {
		t.laz[right] = t.Compose(t.laz[k], t.laz[right])
	}
	t.laz[k] = t.Id
}

func (t *LazySegTree) updateFrom(l, r int) {
	for i := 1; i <= t.Log; i++ {
		if ((l >> i) << i) != l {
			node := l >> i
			left := 2 * node
			rightNode := left + 1
			t.dat[node] = t.Op(t.dat[left], t.dat[rightNode])
		}
		if ((r >> i) << i) != r {
			node := (r - 1) >> i
			left := 2 * node
			rightNode := left + 1
			t.dat[node] = t.Op(t.dat[left], t.dat[rightNode])
		}
	}
}

func (t *LazySegTree) AllProd() S {
	return t.dat[1]
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	return n
}

func nextLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return n
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	Q := nextInt(scanner)

	tenmod = make([]int, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	inv9 = modInv(9)

	dat := make([]S, N)
	for i := 0; i < N; i++ {
		power := tenmod[N-i-1]
		dat[i] = S{power, i, i}
	}

	segTree := NewLazySegTree(dat, op, S_E, mapS, compositeF, F{0, 0})

	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	for q := 0; q < Q; q++ {
		l := nextInt(scanner) - 1
		r := nextInt(scanner) - 1
		D := nextLong(scanner)
		Dint := int(D % MOD2)

		segTree.Apply(l, r+1, F{Dint, N})
		res := segTree.AllProd().Sum
		fmt.Fprintf(out, "%d\n", res)
		out.Flush()
	}
}
// End of Code
