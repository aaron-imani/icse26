package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Fields(scanner.Text())
	max, _ := strconv.Atoi(inputs[0])
	min := max

	for i := 1; i < N; i++ {
		scanner.Scan()
		inputs := strings.Fields(scanner.Text())
		num, _ := strconv.Atoi(inputs[0])
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	fmt.Println(max - min)
}

// End of Code
