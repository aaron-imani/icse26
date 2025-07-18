package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	if a*b >= c*d {
		fmt.Println(a * b)
	} else if a*b <= c*d {
		fmt.Println(c * d)
	}
} // End of Code
