package main

import (
	"fmt"
	"math"
)

func main() {
	var intA int
	if _, err := fmt.Scan(&intA); err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	dbAncer := math.Pow(float64(intA), 3)
	intAncer := int(dbAncer)
	fmt.Println(intAncer)
}
// End of Code
