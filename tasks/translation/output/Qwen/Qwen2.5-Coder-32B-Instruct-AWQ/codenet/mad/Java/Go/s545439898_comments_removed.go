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
	countStr := scanner.Text()
	count, err := strconv.Atoi(countStr)
	if err != nil {
		fmt.Println("Error reading count:", err)
		return
	}

	givingNumbers := make([]int, count)
	for i := 0; i < count; i++ {
		scanner.Scan()
		numStr := scanner.Text()
		num, err := strconv.Atoi(numStr)
		if err != nil {
			fmt.Println("Error reading number:", err)
			return
		}
		givingNumbers[i] = num
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
