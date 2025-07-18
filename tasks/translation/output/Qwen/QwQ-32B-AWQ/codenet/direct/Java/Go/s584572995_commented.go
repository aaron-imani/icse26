package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod int64 = 1e9 + 7

var to [][]int
var dp []int

func main() {
	N := readInt()
	to = make([][]int, N)
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		a := readInt() - 1
		b := readInt() - 1
		to[a] = append(to[a], b)
		to[b] = append(to[b], a)
		edges[i][0] = b
		edges[i][1] = a
	}
	dp = make([]int, N)
	dfs(0, -1)

	var mulsum int64
	for _, e := range edges {
		c1 := e[0]
		c2 := e[1]
		var child int
		if dp[c1] < dp[c2] {
			child = c1
		} else {
			child = c2
		}
		a := int64(dp[child])
		b := int64(N) - a
		term1 := (modpow(2, a) - 1) % mod
		term2 := (modpow(2, b) - 1) % mod
		mul := (term1 * term2) % mod
		mulsum = (mulsum + mul) % mod
	}

	cases := modpow(2, int64(N))
	PN := (mulsum + cases - 1 + mod) % mod
	BN := int64(N) * modpow(2, int64(N-1)) % mod
	WN := (PN - BN + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := WN * invCases % mod
	fmt.Println(ans)
}

func dfs(v, parent int) {
	dp[v] = 1
	for _, next := range to[v] {
		if next != parent {
			dfs(next, v)
			dp[v] += dp[next]
		}
	}
}

func modpow(x, y int64) int64 {
	res := int64(1)
	x %= mod
	for y > 0 {
		if y%2 != 0 {
			res = res * x % mod
		}
		x = x * x % mod
		y = y / 2
	}
	return res
}

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// End of Code
