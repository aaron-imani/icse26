package main

import (
	"fmt"
)

func solve(d int) int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	for {
		var d int
		_, err := fmt.Scan(&d)
		if err != nil {
			break
		}
		fmt.Println(solve(d))
	}
}

// End of Code
