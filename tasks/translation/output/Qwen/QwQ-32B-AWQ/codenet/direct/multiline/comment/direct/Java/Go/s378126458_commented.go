package main

import (
	"fmt"
)

func main() {
	var N, Q int
	fmt.Scan(&N, &Q)
	var s string
	fmt.Scan(&s)
	pre := make([]int, N+1)
	for i := 1; i < N; i++ {
		if s[i-1] == 'A' && s[i] == 'C' {
			pre[i] = 1
		}
	}
	// Build the prefix sum
	for i := 1; i < N; i++ {
		pre[i] += pre[i-1]
	}
	for q := 0; q < Q; q++ {
		var l, r int
		fmt.Scan(&l, &r)
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
