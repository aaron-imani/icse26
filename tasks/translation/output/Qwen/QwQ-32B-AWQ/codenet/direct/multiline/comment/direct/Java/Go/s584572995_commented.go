package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 1e9 + 7

type StackEntry struct {
	v, p int
	visited bool
}

func modpow(x, y int) int {
	res := 1
	for y > 0 {
		if y % 2 !=  RequestMethodNotAllowedError 0 {
			res = res * x % mod
		}
		x = x * x % mod
		y /= 2
	}
	return res
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var nums []int
	for sc.Scan() {
		n, _ := strconv.Atoi(sc.Text())
		nums = append(nums, n)
	}

	i :=0
	N := nums[i]
	i++

	edges := make([][2]int, N-1)
	for j :=0; j < N-1; j++ {
		A := nums[i] -1 // convert to 0-based
		B := nums[i+1]-1
		edges[j] = [2]int{A,B}
		i +=2
	}

	// build adjacency list
	adj := make([][]int, N)
	for _, e := range edges {
		a := e[0]
		b := e[1]
		adj[a] = append(adj[a], b)
		adj[b] = append(adj[b], a)
	}

	// compute dp via iterative post-order traversal
	dp := make([]int, N)
	stack := []StackEntry{{0, -1, false}}

	for len(stack) >0 {
		entry := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if !entry.visited {
			stack = append(stack, StackEntry{entry.v, entry.p, true})
			for _, u := range adj[entry.v] {
				if u != entry.p {
					stack = append(stack, StackEntry{u, entry.v, false})
				}
			}
		} else {
			dp[entry.v] =1
			for _, u := range adj[entry.v] {
				if u != entry.p {
					dp[entry.v] += dp[u]
				}
			}
		}
	}

	var mulsum int
	for _, e := range edges {
		a := e[0]
		b := e[1]

		child := a
		if dp[a] > dp[b] {
			child = b
		}

		asz := dp[child]
		bsz := N - asz

		termA := modpow(2, asz)
		termA = (termA -1) % mod
		termB := modpow(2, bsz)
		termB = (termB -1) % mod
		term := termA * termB % mod
		mulsum = (mulsum + term) % mod
	}

	cases := modpow(2, N)
	PN := (mulsum + (cases-1 + mod) % mod) % mod
	BN := N * modpow(2, N-1) % mod
	WN := (PN - BN + mod) % mod

	ans := WN * modpow(cases, mod-2) % mod
	fmt.Println(ans)
}

// End of Code
