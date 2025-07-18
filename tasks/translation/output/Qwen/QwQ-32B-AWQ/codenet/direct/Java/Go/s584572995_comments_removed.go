package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var mod = 1000000007
var to [][]int
var dp []int

func modpow(x, y int) int {
	if y == 0 {
		return 1
	}
	x %= mod
	res := 1
	for y > 0 {
		if y%2 != 0 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		y = y / 2
	}
	return res
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	ptr := 0
	N, _ := strconv.Atoi(tokens[ptr])
	ptr++
	to = make([][]int, N)
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A, _ := strconv.Atoi(tokens[ptr])
		B, _ := strconv.Atoi(tokens[ptr+1])
		ptr += 2
		A--
		B--
		edges[i][0] = B
		edges[i][1] = A
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
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
		term1 := (modpow(2, a)-1+mod) % mod
		term2 := (modpow(2, b)-1+mod) % mod
		mul := (term1 * term2) % mod
		mulsum = (mulsum + mul) % mod
	}
	cases := modpow(2, N)
	PN := (mulsum + cases - 1) % mod
	if PN < 0 {
		PN += mod
	}
	BN := (N * modpow(2, N-1)) % mod
	WN := (PN - BN + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := (int64(WN) * int64(invCases)) % mod
	fmt.Println(ans % mod)
}

// End of Code
