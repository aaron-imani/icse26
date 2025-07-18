package main

import (
	"fmt"
	"strconv"
	"strings"
)

var d int

func read() bool {
	var input string
	fmt.Scanln(&input)
	if input == "" {
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
}
// End of Code
