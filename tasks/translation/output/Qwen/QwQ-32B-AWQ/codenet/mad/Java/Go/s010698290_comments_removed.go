package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)

	solved := make([]bool, n+1)
	penalty := make([]int, n+1)

	for i := 0; i < m; i++ {
		var num int
		var str string
		fmt.Scanf("%d %s", &num, &str)
		if str[0] == 'A' {
			solved[num] = true
		} else {
			if !solved[num] {
				penalty[num]++
			}
		}
	}

	correct := 0
	totalPenalty := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correct++
			totalPenalty += penalty[i]
		}
	}

	fmt.Printf("%d %d\n", correct, totalPenalty) // End of Code
}
