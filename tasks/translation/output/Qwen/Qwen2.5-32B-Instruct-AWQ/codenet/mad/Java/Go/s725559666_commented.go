package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	aStr, _ := reader.ReadString('\n')
	bStr, _ := reader.ReadString('\n')
	cStr, _ := reader.ReadString('\n')

	a, _ := strconv.Atoi(strings.TrimSpace(aStr))
	b, _ := strconv.Atoi(strings.TrimSpace(bStr))
	c, _ := strconv.Atoi(strings.TrimSpace(cStr))

	if a < b && b < c && a < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
