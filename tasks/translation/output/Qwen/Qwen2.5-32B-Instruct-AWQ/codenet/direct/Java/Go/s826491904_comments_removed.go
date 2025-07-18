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
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	max, _ := strconv.Atoi(strings.Fields(scanner.Text())[0])
	min := max

	for i := 1; i < N; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(strings.Fields(scanner.Text())[0])
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
