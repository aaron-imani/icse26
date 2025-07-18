package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var count int
	scanner.Scan()
	countStr := scanner.Text()
	count = strconv.Atoi(countStr)

	numbers := make([]int, count)
	for i := 0; i < count; i++ {
		scanner.Scan()
		numStr := scanner.Text()
		num := strconv.Atoi(numStr)
		numbers[i] = num
	}

	for i := len(numbers) - 1; i >= 0; i-- {
		fmt.Printf("%d", numbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// End of Code
