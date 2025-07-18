package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solve(n, m int64) int64 {
	if n == 0 {
		return 0
	}
	if n == m {
		return 0
	}
	if n > m {
		remainder := n % m
		return min(m-remainder, remainder)
	}
	return min(m-n, n)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, m int64
	if scanner.Scan() {
		nStr := scanner.Text()
		n, _ = strconv.ParseInt(nStr, 10, 64)
	} else {
		fmt.Println(0)
		return
	}
	if scanner.Scan() {
		mStr := scanner.Text()
		m, _ = strconv.ParseInt(mStr, 10, 64)
	} else {
		fmt.Println(0)
		return
	}
	fmt.Println(solve(n, m))
}
// End of Code
