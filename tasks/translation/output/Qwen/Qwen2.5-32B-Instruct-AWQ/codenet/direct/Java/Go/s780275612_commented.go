package main

import (
	"fmt"
	"math"
)

func main() {
	var intA int
	fmt.Scan(&intA)

	dbAnswer := math.Pow(float64(intA), 3)
	intAnswer := int(dbAnswer)
	fmt.Println(intAnswer)
}

// End of Code
