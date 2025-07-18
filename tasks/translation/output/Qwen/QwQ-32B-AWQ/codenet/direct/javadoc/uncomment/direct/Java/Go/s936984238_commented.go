package main

import (
	"fmt"
	"sort"
)

func main() {
	for {
		var n int
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		scores := make([]int, n)
		for i := range scores {
			fmt.Scan(&scores[i])
		}
		sort.Ints(scores)
		sum := 0
		for i := 1; i < n-1; i++ {
			sum += scores[i]
		}
		fmt.Println(sum / (n-2))
	}
}

// End of Code
