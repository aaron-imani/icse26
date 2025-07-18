package main

import "fmt"

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	product1 := a * b
	product2 := c * d
	if product1 >= product2 {
		fmt.Println(product1)
	} else {
		fmt.Println(product2)
	}
	// End of Code
}
