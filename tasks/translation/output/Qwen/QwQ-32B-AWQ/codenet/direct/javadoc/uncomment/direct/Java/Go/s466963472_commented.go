package main

import "fmt"

func solve(d int) int {
	sum := 0
	for i := 1; ; i++ {
		x := i * d
		if x >= 600 {
			break
		}
		sum += d * x * x
	}
	return sum
}

func main() {
	var d int
	for {
		if _, err := fmt.Scan(&d); err != nil {
			break
		}
		fmt.Println(solve(d))
	}
}

// End of Code
