package main

import (
	"fmt"
)

func main() {
	var count int
	fmt.Scan(&count)
	numbers := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&numbers[i])
	}
	for i := count - 1; i >= 0; i-- {
		fmt.Printf("%d", numbers[i])
		if i != 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// End of Code
