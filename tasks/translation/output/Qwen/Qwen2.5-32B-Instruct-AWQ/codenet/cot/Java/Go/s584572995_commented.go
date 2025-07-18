package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1e9 + 7
var to [][]int
var dp []int

func main() {
	fs := NewFastScanner(os.Stdin)
	N := fs.NextInt()
	to = make([][]int, N)
	for i := 0; i < N; i++ {
		to[i] = make([]int, 0)
	}
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A := fs.NextInt() - 1
		B := fs.NextInt() - 1
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i][0] = B
		edges[i][1] = A
	}
	dp = make([]int, N)
	rec(0, -1)
	mulsum := 0
	for _, e := range edges {
		candidate1 := e[0]
		candidate2 := e[1]
		child := candidate1
		if dp[candidate1] > dp[candidate2] {
			child = candidate2
		}
		a := dp[child]
		b := N - a
		mul := (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
		mulsum += mul
		mulsum %= mod
	}
	cases := modpow(2, N)
	PN := (mulsum + (cases - 1 + mod) % mod) % mod
	BN := N * modpow(2, N-1) % mod
	WN := (PN - BN + mod) % mod
	ans := WN * modpow(cases, mod-2)
	ans %= mod
	fmt.Println(ans)
}

func rec(v int, parent int) int {
	res := 1
	for _, next := range to[v] {
		if next == parent {
			continue
		}
		res += rec(next, v)
	}
	dp[v] = res
	return res
}

func modpow(x int, y int) int {
	if y == 0 {
		return 1
	}
	if y%2 != 0 {
		return x * modpow(x, y-1) % mod
	}
	tmp := modpow(x, y/2)
	return tmp * tmp % mod
}

type FastScanner struct {
	reader *bufio.Reader
}

func NewFastScanner(r io.Reader) *FastScanner {
	return &FastScanner{reader: bufio.NewReader(r)}
}

func (fs *FastScanner) Next() string {
	s, _ := fs.reader.ReadString(' ')
	return strings.TrimSpace(s)
}

func (fs *FastScanner) NextInt() int {
	s := fs.Next()
	n, _ := strconv.Atoi(s)
	return n
}

// End of Code
