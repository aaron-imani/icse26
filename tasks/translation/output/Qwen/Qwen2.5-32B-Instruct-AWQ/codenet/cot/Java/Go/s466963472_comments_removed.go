package main

import (
	"fmt"
	"strconv"
)

var d int

func read() bool {
	input, _ := fmt.Scanln()
	if input == 0 {
		return false
	}
	d, _ = strconv.Atoi(input)
	return true
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
	// End of Code
