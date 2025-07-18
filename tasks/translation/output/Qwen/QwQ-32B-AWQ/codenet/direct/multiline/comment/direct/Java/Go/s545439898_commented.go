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
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, strings.Fields(scanner.Text())...)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading stdin:", err)
		os.Exit(1)
	}
	countStr := tokens[0]
	count, _ := strconv.Atoi(countStr)
	numbers := make([]int, count)
	for i := 0; i < count; i++ {
		numStr := tokens[i+1]
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
