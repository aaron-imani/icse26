package main

import (
	"fmt"
)

func main() {
	solve()
}

func solve() {
	var N int
	fmt.Scanf("%d", &N)
	var max, min int
	fmt.Scanf("%d", &max)
	min = max
	for i := 1; i < N; i++ {
		var in int
		fmt.Scanf("%d", &in)
		if in > max {
			max = in
		}
		if in < min {
			min = in
		}
	}
	fmt.Println(max - min) // End of Code
