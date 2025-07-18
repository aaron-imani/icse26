package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	var max, min int
	fmt.Scan(&max)
	min = max
	for i := 1; i < N; i++ {
		var num int
		fmt.Scan(&num)
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	fmt.Println(max - min)
}

// End of Code
