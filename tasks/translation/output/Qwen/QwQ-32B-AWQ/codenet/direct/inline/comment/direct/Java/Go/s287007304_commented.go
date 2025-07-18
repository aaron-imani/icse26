package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()

	parts := strings.Fields(line)
	aStr := parts[0]
	bStr := parts[1]

	a, _ := strconv.Atoi(aStr)
	b, _ := strconv.Atoi(bStr)

	if b%a == 0 {
		fmt.Println(a + b)
	} else {
		fmt.Println(b - a)
	}
}

// End of Code
