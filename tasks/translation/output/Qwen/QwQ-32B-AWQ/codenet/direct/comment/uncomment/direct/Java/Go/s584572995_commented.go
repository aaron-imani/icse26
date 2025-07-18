package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

const mod = 1e9 + 7

func main() {
	var tokens []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		tokens = append(tokens, parts...)
	}
	idx := 0
	N := atoi(tokens[idx])
	idx++
	to := make([][]int, N)
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A := atoi(tokens[idx])-1
		idx++
		B := atoi(tokens[idx])-1
		idx++
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i] = [2]int{B, A}
	}
	dp := make([]int, N)
	var dfs func(v, parent int) int
	dfs = func(v, parent int) int {
		size := 1
		for _, next := range to[v] {
			if next == parent {
				continue
			}
			size += dfs(next, v)
		}
		dp[v] = size
		return size
	}
	dfs(0, -1)
	var mulsum int = 0
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
		pow2a := modpow(2, a)
		term1 := (pow2a - 1) % mod
		pow2b := modpow(2, b)
		term2 := (pow2b - 1) % mod
		mul := term1 * term2 % mod
		mulsum = (mulsum + mul) % mod
	}
	cases := modpow(2, N)
	PN := (mulsum + (cases-1+mod)) % mod
	BN := (N * modpow(2, N-1)) % mod
	WN := (PN - BN + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := WN * invCases % mod
	println(ans)
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

func atoi(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

// End of Code
