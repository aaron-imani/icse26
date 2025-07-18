package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	if a < b && b < c && a < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
