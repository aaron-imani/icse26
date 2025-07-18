package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	var first int
	fmt.Scan(&first)
	max, min := first, first

	for i := 0; i < N-1; i++ {
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
