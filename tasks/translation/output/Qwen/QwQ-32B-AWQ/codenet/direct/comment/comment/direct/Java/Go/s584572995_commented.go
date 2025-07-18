package main

import (
	"bufio"
	"os"
	"strconv"
)

const mod = 1e9 + 7

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	idx := 0

	N, _ := strconv.Atoi(tokens[idx])
	idx++

	edges := make([][2]int, N-1)
	to := make([][]int, N)

	for i := 0; i < N-1; i++ {
		A, _ := strconv.Atoi(tokens[idx])
		B, _ := strconv.Atoi(tokens[idx+1])
		idx += 2
		A--
		B--
		edges[i][0] = B
		edges[i][1] = A
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
	}

	dp := make([]int, N)
	var rec func(v, parent int) int
	rec = func(v, parent int) int {
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
		term2 := (modpow(2, b) - 1) % mod
		product := term1 * term2 % mod
		mulsum = (mulsum + product) % mod
	}

	cases := modpow(2, N)
	casesMinus1 := (cases - 1 + mod) % mod
	PN := (mulsum + casesMinus1) % mod

	BN := (N * modpow(2, N-1)) % mod
	WN := (PN - BN + mod) % mod

	invCases := modpow(cases, mod-2)
	ans := WN * invCases % mod

	fmt.Println(ans)
}

func modpow(x, y int) int {
	res := 1
	x %= mod
	for y > 0 {
		if y%2 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		y /= 2
	}
	return res
}

// End of Code
