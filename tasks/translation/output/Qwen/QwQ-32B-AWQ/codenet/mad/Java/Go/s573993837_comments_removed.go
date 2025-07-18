package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var tokens []string
	for sc.Scan() {
		tokens = append(tokens, sc.Text())
	}
	t, _ := strconv.ParseInt(tokens[0], 10, 64)
	idx := 1
	for i := int64(0); i < t; i++ {
		n, _ := strconv.ParseInt(tokens[idx], 10, 64)
		m, _ := strconv.ParseInt(tokens[idx+1], 10, 64)
		idx += 2
		if n == 0 || n == m {
			fmt.Println(0)
		} else {
			if n > m {
				n %= m
			}
			fmt.Println(min(n, m-n))
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
// End of Code
