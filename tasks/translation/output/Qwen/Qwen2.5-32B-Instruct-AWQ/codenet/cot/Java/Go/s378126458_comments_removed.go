package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N, Q int
	fmt.Scanf("%d %d", &N, &Q)
	s := make([]byte, N)
	fmt.Scanf("%s", &s)
	pre := make([]int, N+1)

	for i := 1; i < N; i++ {
		if s[i-1] == 'A' && s[i] == 'C' {
			pre[i] = 1
		}
	}

	for i := 1; i < N; i++ {
		pre[i] += pre[i-1]
	}

	for Q > 0 {
		var l, r int
		fmt.Scanf("%d %d", &l, &r)
		r--
		fmt.Println(pre[r] - pre[l-1])
		Q--
	}
	// End of Code
}
