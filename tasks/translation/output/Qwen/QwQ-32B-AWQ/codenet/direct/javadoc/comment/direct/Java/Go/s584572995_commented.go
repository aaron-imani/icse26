package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var mod int64 = 1e9 + 7

func modpow(x, y int64) int64 {
	res := int64(1)
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	if !scanner.Scan() {
		panic("No input")
	}
	N, _ = strconv.Atoi(scanner.Text())
	adj := make([][]int, N)
	edges := make([][2]int, 0, N-1)
	for i := 0; i < N-1; i++ {
		if !scanner.Scan() {
			panic("No input for A")
		}
		A := scanner.Text()
		if !scanner.Scan() {
			panic("No input for B")
		}
		B := scanner.Text()
		a, _ := strconv.Atoi(A)
		b, _ := strconv.Atoi(B)
		a--
		b--
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
		edges = append(edges, [2]int{b, a})
	}
	dp := make([]int, N)
	var dfs func(v, parent int) int
	dfs = func(v, parent int) int {
		res := 1
		for _, next := range adj[v] {
			if next != parent {
				res += dfs(next, v)
			}
		}
		dp[v] = res
		return res
	}
	dfs(0, -1)
	var mulsum int64 = 0
	for _, e := range edges {
		candidate1 := e[0]
		candidate2 := e[1]
		var child int
		if dp[candidate1] < dp[candidate2] {
			child = candidate1
		} else {
			child = candidate2
		}
		a := dp[child]
		b := N - a
		term1 := (modpow(int64(2), int64(a)) - 1) % mod
		term2 := (modpow(int64(2), int64(b)) - 1) % mod
		term := term1 * term2 % mod
		mulsum = (mulsum + term) % mod
	}
	cases := modpow(int64(2), int64(N))
	PN := (mulsum + (cases-1+mod)%mod) % mod
	bn := int64(N) * modpow(int64(2), int64(N-1)) % mod
	wn := (PN - bn + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := wn * invCases % mod
	fmt.Println(ans)
}

// End of Code
