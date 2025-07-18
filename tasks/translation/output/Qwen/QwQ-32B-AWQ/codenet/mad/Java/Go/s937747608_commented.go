package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int
	fmt.Scanf("%d%d%d%d", &a, &b, &c, &d) // Removed spaces in format for better handling
	
	if a*b >= c*d {
		fmt.Println(a * b)
	} else {
		fmt.Println(c * d)
	}
}

// End of Code
