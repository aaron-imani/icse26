package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	if a%2 == 0 || b%2 == 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

// End of Code
