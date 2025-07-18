package main

import (
	"fmt"
	"strconv"
)

func main() {
	var count int
	fmt.Scan(&count)
	givingNumbers := make([]int, count)

	for i := 0; i < count; i++ {
		var num int
		fmt.Scan(&num)
		givingNumbers[i] = num
	}

	for i := count - 1; 0 <= i; i-- {
		fmt.Print(givingNumbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}

	fmt.Println()
}
// End of Code
