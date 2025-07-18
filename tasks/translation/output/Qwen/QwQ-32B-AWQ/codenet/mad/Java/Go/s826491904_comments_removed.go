// Negative side's correct code
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

	var num int // Declared outside the loop to avoid redeclaration
	for i := 1; i < N; i++ {
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
