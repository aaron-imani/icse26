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
	count, _ := strconv.Atoi(scanner.Text())

	givingNumbers := make([]int, count)

	for i := 0; i < count; i++ {
		scanner.Scan()
		givingNumbers[i], _ = strconv.Atoi(scanner.Text())
	}

	for i := count - 1; i >= 0; i-- {
		fmt.Print(givingNumbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}

	fmt.Println()
}

// End of Code
