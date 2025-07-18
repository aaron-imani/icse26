package main

import (
	"fmt"
)

var d int

func read() bool {
	_, err := fmt.Scan(&d)
	return err == nil
}

func solve() int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	for read() {
		fmt.Println(solve())
	}
}
// End of Code
