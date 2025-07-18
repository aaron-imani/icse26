package main

import (
	"fmt"
	"math"
)

func main() {
	var intA int
	fmt.Scanf("%d", &intA)

	dbAncer := math.Pow(float64(intA), 3)
	intAncer := int(dbAncer)
	fmt.Println(intAncer)
	// End of Code
