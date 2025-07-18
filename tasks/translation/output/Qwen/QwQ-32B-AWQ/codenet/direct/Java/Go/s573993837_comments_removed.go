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
		fmt.Println(0)
		return
	}
	nStr := scanner.Text()
	n, _ = strconv.ParseInt(nStr, 10, 64)
	if !scanner.Scan() {
		fmt.Println(0)
		return
	}
	mStr := scanner.Text()
	m, _ = strconv.ParseInt(mStr, 10, 64)

	if n == 0 {
		fmt.Println(0)
		return
	}
	if n == m {
		fmt.Println(0)
		return
	}
	if n > m {
		rem := n % m
		fmt.Println(min(rem, m-rem))
	} else {
		fmt.Println(min(m-n, n))
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
} // End of Code
