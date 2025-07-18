package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for t > 0 {
		scanner.Scan()
		input := strings.Fields(scanner.Text())
		n, _ := strconv.ParseInt(input[0], 10, 64)
		m, _ := strconv.ParseInt(input[1], 10, 64)
		if n == 0 {
			fmt.Println(0)
			continue
		}
		if n == m {
			fmt.Println(0)
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Println(min(m-n, n))
			continue
		}
		fmt.Println(min(m-n, n))
		t--
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	solve()
}

// End of Code
