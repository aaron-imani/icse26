package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1e9 + 7

func modpow(x, y int) int {
	res := 1
	x %= mod
	for y > 0 {
		if y%2 != 0 {
			res = res * x % mod
		}
		x = x * x % mod
		y /= 2
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	N, _ := strconv.Atoi(tokens[0])
	to := make([][]int, N)
	edges := make([][2]int, N-1)
	idx := 1
	for i := 0; i < N-1; i++ {
		aStr := tokens[idx]
		bStr := tokens[idx+1]
		A, _ := strconv.Atoi(aStr)
		B, _ := strconv.Atoi(bStr)
		A--
		B--
		edges[i] = [2]int{A, B}
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		idx += 2
	}

	dp := make([]int, N)
	var dfs func(v, parent int) int
	dfs = func(v, parent int) int {
		res := 1
		for _, next := range to[v] {
			if next == parent {
				continue
			}
			res += dfs(next, v)
		}
		dp[v] = res
		return res
	}
	dfs(0, -1)

	var mulsum int
	for _, e := range edges {
		a, b := e[0], e[1]
		child := a
		if dp[a] > dp[b] {
			child = b
		}
		aSize := dp[child]
		bSize := N - aSize
		aTerm := (modpow(2, aSize) - 1) % mod
		bTerm := (modpow(2, bSize) - 1) % mod
		term := aTerm * bTerm % mod
		mulsum = (mulsum + term) % mod
	}

	cases := modpow(2, N)
	PN := (mulsum + (cases-1+mod)%mod) % mod
	BN := N * modpow(2, N-1) % mod
	WN := (PN - BN + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := WN * invCases % mod
	fmt.Println(ans)
}

// End of Code
