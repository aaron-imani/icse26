package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	queue := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&queue[i])
	}
	sort.Ints(queue)
	sum := 0
	for i := 0; i < n-1; i++ {
		sum += queue[i]
	}
	if queue[n-1] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
	// End of Code
}
