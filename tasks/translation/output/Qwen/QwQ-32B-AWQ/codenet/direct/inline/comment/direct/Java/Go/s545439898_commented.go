package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	countStr := scanner.Text()
	count, _ := strconv.Atoi(countStr)

	numbers := make([]int, count)
	for i := 0; i < count; i++ {
		scanner.Scan()
		numStr := scanner.Text()
		num, _ := strconv.Atoi(numStr)
		numbers[i] = num
	}

	for i := len(numbers) - 1; i >= 0; i-- {
		fmt.Print(numbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// End of Code
