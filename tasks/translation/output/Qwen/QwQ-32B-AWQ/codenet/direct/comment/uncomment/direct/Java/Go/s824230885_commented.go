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
	nStr := scanner.Text()
	n, _ := strconv.Atoi(nStr)

	scanner.Scan()
	numbersStr := scanner.Text()
	numbers := make([]int, 0, n)
	for _, numStr := range strings.Split(numbersStr, " ") {
		num, _ := strconv.Atoi(numStr)
		numbers = append(numbers, num)
	}

	max := 0
	count := 0
	for _, num := range numbers {
		if num >= max {
			max = num
			count++
		}
	}
	fmt.Println(count)
}

// End of Code
