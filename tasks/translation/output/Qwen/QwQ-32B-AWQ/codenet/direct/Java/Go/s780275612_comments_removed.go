package main

import (
	"fmt"
	"math"
)

func main() {
	var a int
	fmt.Scanln(&a)
	cube := math.Pow(float64(a), 3)
	fmt.Println(int(cube))
}

// End of Code
