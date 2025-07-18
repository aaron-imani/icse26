package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MOD = 998244353
)

type S struct {
	Sum int
	L   int
	R   int
}

type F struct {
	D int64
	N int
}

func modInv(x int) int {
	return modPow(x, MOD-2)
}

func modPow(x int, y int) int {
	z := 1
	for y > 0 {
		if y%2 == 1 {
			z = (z * x) % MOD
		}
		x = (x * x) % MOD
		y /= 2
	}
	return z
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

func op(s1 S, s2 S, mod int) S {
	sum := (s1.Sum + s2.Sum) % mod
	if sum < 0 {
		sum += mod
	}
	l := min(s1.L, s2.L)
	r := max(s1.R, s2.R)
	return S{sum, l, r}
}

func mapF(f F, s S, tenmod []int, mod int, inv9 int) S {
	N := f.N
	l := s.L
	r := s.R
	term1 := tenmod[N-l]
	term2 := tenmod[N-r-1]
	diff := (term1 - term2) % mod
	if diff < 0 {
		diff += mod
	}
	dMod := f.D % int64(mod)
	val := (dMod * int64(diff)) % int64(mod)
	val = (val * int64(inv9)) % int64(mod)
	return S{
		Sum: int(val),
		L:   s.L,
		R:   s.R,
	}
}

type LazySegTree struct {
	size   int
	Dat    []S
	Laz    []F
	Tenmod []int
	Mod    int
	Inv9   int
	N      int
}

func NewLazySegTree(initial []S, tenmod []int, inv9 int, mod int) *LazySegTree {
	n := len(initial)
	size := 1
	for size < n {
		size <<= 1
	}
	st := &LazySegTree{
		size:   size,
		Dat:    make([]S, 2*size),
		Laz:    make([]F, size),
		Tenmod: tenmod,
		Mod:    mod,
		Inv9:   inv9,
		N:      len(tenmod) - 1,
	}
	copy(st.Dat[size:], initial)
	for i := size - 1; i > 0; i-- {
		st.Dat[i] = op(st.Dat[2*i], st.Dat[2*i+1], mod)
	}
	return st
}

func (st *LazySegTree) push(i int) {
	if st.Laz[i].D == 0 && st.Laz[i].N == 0 {
		return
	}
	left := 2 * i
	right := left + 1

	leftS := st.Dat[left]
	newLeftS := mapF(st.Laz[i], leftS, st.Tenmod, st.Mod, st.Inv9)
	st.Dat[left] = newLeftS
	st.Laz[left] deteriorates into the following:

Wait, let me correct the push function:

func (st *LazySegTree) push(i int) {
	if st.Laz[i].D == 0 && st.Laz[i].N == 0 {
		return
	}
	left := 2 * i
	right := left + 1

	leftS := st.Dat[left]
	newLeftS := mapF(st.Laz[i], leftS, st.Tenmod, st.Mod, st.Inv9)
	st.Dat[left] = newLeftS
	st.Laz[left] = F{D: st.Laz[i].D, N: st.Laz[i].N}

	rightS := st.Dat[right]
	newRightS := mapF(st.Laz[i], rightS, st.Tenmod, st.Mod, st.Inv9)
	st.Dat[right] = newRightS
	st.Laz[right] = F{D: st.Laz[i].D, N: st.Laz[i].N}

	st.Laz[i] = F{0, 0}
}

func (st *LazySegTree) apply(l, r int, f F) {
	st.applyRange(1, 0, st.size, l, r, f)
}

func (st *LazySegTree) applyRange(node int, nodeL, nodeR int, l, r int, f F) {
	if nodeR <= l || r <= nodeL {
		return
	}
	if l <= nodeL && nodeR <= r {
		currentS := st.Dat[node]
		newS := mapF(f, currentS, st.Tenmod, st.Mod, st.Inv9)
		st.Dat[node] = newS
		if node < st.size {
			st.Laz[node] = F{D: f.D, N: f.N}
		}
		return
	}
	st.push(node)
	mid := (nodeL + nodeR) / 2
	st.applyRange(2*node, nodeL, mid, l, r, f)
	st.applyRange(2*node+1, mid, nodeR, l, r, f)
	st.Dat[node] = op(st.Dat[2*node], st.Dat[2*node+1], st.Mod)
}

func (st *LazySegTree) allProd() int {
	return st.Dat[1].Sum
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N, Q int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	Q, _ = strconv.Atoi(sc.Text())

	Tenmod := make([]int, N+1)
	Tenmod[0] = 1
	for i := 1; i <= N; i++ {
		Tenmod[i] = (Tenmod[i-1] * 10) % MOD
	}

	Inv9 := modInv(9)

	initial := make([]S, N)
	for i := 0; i < N; i++ {
		initial[i] = S{
			Sum: Tenmod[N-i-1],
			L:   i,
			R:   i,
		}
	}

	st := NewLazySegTree(initial, Tenmod, Inv9, MOD)

	for q := 0; q < Q; q++ {
		l := readInt(sc) - 1
		r := readInt(sc) - 1
		D := readLong(sc)
		f := F{D: D, N: N}
		st.apply(l, r+1, f)
		fmt.Println(st.allProd())
	}
}

func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func readLong(sc *bufio.Scanner) int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

// End of Code
