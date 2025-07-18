package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	fmt.Println(max(0, a-2*b))
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// End of Code
