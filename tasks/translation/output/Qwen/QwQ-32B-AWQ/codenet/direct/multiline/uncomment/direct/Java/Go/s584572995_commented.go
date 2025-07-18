package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1000000007

func modpow(x, y int) int {
	res := 1
	x %= mod
	for y > 0 {
		if y%2 != 0 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		y /= 2
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	N = nextInt(scanner)
	to := make([][]int, N)
	for i := 0; i < N; i++ {
		to[i] = make([]int, 0)
	}
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A := nextInt(scanner) - 1
		B := nextInt(scanner) - 1
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i][0] = B
		edges[i][1] = A
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
	mulsum = 0
	for _, e := range edges {
		candidate1 := e[0]
		candidate2 := e[1]
		var child int
		if dp[candidate1] > dp[candidate2] {
			child = candidate2
		} else {
			child = candidate1
		}
		a := dp[child]
		b := N - a
		part1 := (modpow(2, a) - 1) % mod
		part2 := (modpow(2, b) - 1) % mod
		mul := (part1 * part2) % mod
		mulsum = (mulsum + mul) % mod
	}

	cases := modpow(2, N)
	PN := (mulsum + (cases-1+mod)%mod) % mod
	BN := (N * modpow(2, N-1)) % mod
	WN := (PN - BN + mod) % mod
	invCases := modpow(cases, mod-2)
	ans := (WN * invCases) % mod
	fmt.Println(ans)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	numStr := sc.Text()
	num, _ := strconv.Atoi(numStr)
	return num
}

// End of Code
