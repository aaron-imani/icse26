package main

import (
	"fmt"
)

func main() {
	solve()
}

func solve() {
	var a, b int
	fmt.Scan(&a, &b)
	res := a - 2*b
	if res < 0 {
		fmt.Println(0)
	} else {
		fmt.Println(res)
	}
}

// End of Code
