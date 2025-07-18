package main

import (
	"fmt"
	"sort"
)

func main() {
	for {
		scores, ok := read()
		if !ok {
			break
		}
		solve(scores)
	}
}

func read() ([]int, bool) {
	var n int
	fmt.Scan(&n)
	if n == 0 {
		return nil, false
	}
	scores := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&scores[i])
	}
	return scores, true
}

func solve(scores []int) {
	sort.Ints(scores)
	sum := 0
	for i := 1; i < len(scores)-1; i++ {
		sum += scores[i]
	}
	fmt.Println(sum / (len(scores)-2))
}

// End of Code
