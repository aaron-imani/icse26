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
	line := scanner.Text()
	parts := strings.Split(line, " ")
	numbers := make([]int, 0, len(parts))
	for _, p := range parts {
		num, _ := strconv.Atoi(p)
		numbers = append(numbers, num)
	}

	max := 0
	output := 0
	for _, num := range numbers {
		if num >= max {
			output++
			max = num
		}
	}
	fmt.Println(output)
}

// End of Code
