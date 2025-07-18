package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, m int64
	if !scanner.Scan() {
		fmt.Fprintln(os.Stderr, "Error reading first number")
		os.Exit(1)
	}
	nStr := scanner.Text()
	n, _ = strconv.ParseInt(nStr, 10, 64)

	if !scanner.Scan() {
		fmt.Fprintln(os.Stderr, "Error reading second number")
		os.Exit(1)
	}
	mStr := scanner.Text()
	m, _ = strconv.ParseInt(mStr, 10, 64)

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
		mod := n % m
		return min(mod, m-mod)
	}
	return min(m-n, n)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
// End of Code
