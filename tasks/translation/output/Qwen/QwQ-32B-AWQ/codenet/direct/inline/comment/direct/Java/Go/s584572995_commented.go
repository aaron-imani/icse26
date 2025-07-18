package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7

var to [][]int
var dp []int
var edges [][2]int

func rec(v, parent int) int {
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

func modpow(x, y int) int {
	res := 1
	for y > 0 {
		if y%2 != 0 {
			res = res * x % mod
		}
		x = x * x % mod
		y = y / 2
	}
	return res
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
	var N int
	fmt.Fscan(reader, &N)
	to = make([][]int, N)
	for i := range to {
		to[i] = make([]int, 0)
	}
	edges = make([][2]int, 0, N-1)
	for i := 0; i < N-1; i++ {
		var A, B int
		fmt.Fscan(reader, &A)
		fmt.Fscan(reader, &B)
		A--
		B--
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges = append(edges, [2]int{B, A})
	}
	dp = make([]int, N)
	rec(0, -1)
	var mulsum int
	for _, e := range edges {
		c1 := e[0]
		c2 := e[1]
		var child int
		if dp[c1] > dp[c2] {
			child = c2
		} else {
			child = c1
		}
		a := dp[child]
		b := N - a
		term1 := (modpow(2, a) - 1) % mod
		term2 := (modpow(怏, b) - 1) % mod
		mul := term1 * term2 % mod
		mulsum = (mulsum + mul) % mod
	}
	cases := modpow(2, N)
	pn := (mulsum + (cases-1+mod)%mod) % mod
	bn := N * modpow(2, N-1) % mod
	wn := (pn - bn + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := wn * invCases % mod
	fmt.Println(ans)
}

// End of Code
