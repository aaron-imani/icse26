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
		tokens = append(tokens, scanner.Text())
	}
	all := strings.Join(tokens, " ")
	fields := strings.Fields(all)
	if len(fields) < 2 {
		fmt.Fprintln(os.Stderr, "Need at least two numbers")
		os.Exit(1)
	}
	n, err := strconv.ParseInt(fields[0], 10, 64)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing n: %v\n", err)
		os.Exit(1)
	}

	m, err := strconv.ParseInt(fields[1], 10, 64)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing m: %v\n", err)
		os.Exit(1)
	}

	result := solve(n, m)
	fmt.Println(result)
}

func solve(n, m int64) int64 {
	if n == 0 {
		return 0
	}
	if n == m {
		return 0
	}
	if n > m {
		n %= m
	}
	diff := m - n
	return min(n, diff)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
