package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	res := a - 2*b
	if res < 0 {
		res = 0
	}
	fmt.Println(res)
}

// End of Code
