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
	var t int
	if sc.Scan() {
		t, _ = strconv.Atoi(sc.Text())
	}
	for t > 0 {
		t--
		var n, m int64
		if sc.Scan() {
			n, _ = strconv.ParseInt(sc.Text(), 10, 64)
		}
		if sc.Scan() {
			m, _ = strconv.ParseInt(sc.Text(), 10, 64)
		}
		ans := solve(n, m)
		fmt.Println(ans)
	}
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
	return min(m-n, n)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
