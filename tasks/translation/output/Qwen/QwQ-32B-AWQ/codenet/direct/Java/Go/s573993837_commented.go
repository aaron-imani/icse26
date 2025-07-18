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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var t = 1
	for t > 0 {
		t--
		if !scanner.Scan() {
			break
		}
		nStr := scanner.Text()
		n, _ := strconv.ParseInt(nStr, 10, 64)
		if !scanner.Scan() {
			break
		}
		mStr := scanner.Text()
		m, _ := strconv.ParseInt(mStr, 10, 64)

		if n == 0 {
			fmt.Println(0)
			continue
		}
		if n == m {
			fmt.Println(0)
			continue
		}
		if n > m {
			rem := n % m
			fmt.Println(min(m-rem, rem))
			continue
		}
		fmt.Println(min(m-n, n))
	}
}

// End of Code
