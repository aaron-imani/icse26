package main

import (
	"fmt"
)

func main() {
	var count int
	fmt.Scan(&count)
	nums := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&nums[i])
	}
	for i := count - 1; i >= 0; i-- {
		fmt.Print(nums[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// End of Code
