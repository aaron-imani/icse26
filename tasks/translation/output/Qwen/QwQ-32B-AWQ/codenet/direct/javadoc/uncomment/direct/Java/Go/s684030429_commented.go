package main

import (
	"fmt"
)

func solve() {
	var a, b int
	fmt.Scanln(&a, &b)
	result := a - 2*b
	if result < 0 {
		result = 0
	}
	fmt.Println(result)
}

func main() {
	solve()
}
// End of Code
