package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var lines []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading stdin:", err)
		os.Exit(1)
	}

	if len(lines) < 2 {
		fmt.Fprintln(os.Stderr, "Not enough input lines")
		os.Exit(1)
	}

	N, err := strconv.Atoi(lines[0])
	if err != nil {
		fmt.Fprintln(os.Stderr, "Invalid N:", err)
		os.Exit(1)
	}

	elementsStr := strings.Split(lines[1], " ")
	elements := make([]int, len(elementsStr))
	for i, s := range elementsStr {
		num, err := strconv.Atoi(s)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Invalid number: %s\n", s)
			os.Exit(1)
		}
		elements[i] = num
	}

	result := solve(N, elements)
	fmt.Println(result)
}

func solve(N int, list []int) int {
	max := 0
	output := 0
	for i := 0; i < N; i++ {
		if list[i] >= max {
			max = list[i]
			output++
		}
	}
	return output
}

// End of Code
