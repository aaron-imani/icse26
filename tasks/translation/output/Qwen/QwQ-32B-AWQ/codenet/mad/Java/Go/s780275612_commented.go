package main

import (
	"fmt"
	"math"
)

func main() {
	var intA int
	fmt.Scan(&intA)
	intAncer := int(math.Pow(float64(intA), 3))
	fmt.Println(intAncer)
}
// End of Code
