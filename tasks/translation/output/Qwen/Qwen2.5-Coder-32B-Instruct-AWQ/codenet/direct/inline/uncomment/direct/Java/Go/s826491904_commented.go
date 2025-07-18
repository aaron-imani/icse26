package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	var max, min int
	fmt.Scan(&min)
	max = min
	for i := 1; i < N; i++ {
		var in int
		fmt.Scan(&in)
		if in > max {
			max = in
		}
		if in < min {
			min = in
		}
	}
	fmt.Println(max - min)
}
// End of Code
