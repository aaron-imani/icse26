package main

import "fmt"

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	ab := a * b
	cd := c * d
	if ab >= cd {
		fmt.Println(ab)
	} else {
		fmt.Println(cd)
	}
} // End of Code
