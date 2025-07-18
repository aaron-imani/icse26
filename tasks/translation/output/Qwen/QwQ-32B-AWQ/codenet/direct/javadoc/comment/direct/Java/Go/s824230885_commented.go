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
	Nstr := scanner.Text()
	N, _ := strconv.Atoi(Nstr)
	scanner.Scan()
	listStr := scanner.Text()
	parts := strings.Fields(listStr)
	numbers := make([]int, 0, len(parts))
	for _, p := range parts {
		num, _ := strconv.Atoi(p)
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
