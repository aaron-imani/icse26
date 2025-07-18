package main

import (
	"fmt"
)

func main() {
	var intA int
	fmt.Scan(&intA)

	dbAncer := float64(intA) * float64(intA) * float64(intA)
	intAncer := int(dbAncer)
	fmt.Println(intAncer)
}
// End of Code
