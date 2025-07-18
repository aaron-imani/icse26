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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	if sc.Scan() {
		t, _ = strconv.Atoi(sc.Text())
	}
	t = 1

	for i := 0; i < t; i++ {
		var n, m int64
		if sc.Scan() {
			text := sc.Text()
			n, _ = strconv.ParseInt(text, 10, 64)
		}
		if sc.Scan() {
			text := sc.Text()
			m, _ = strconv.ParseInt(text, 10, 64)
		}

		if n == 0 {
			fmt.Fprintln(writer, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(writer, 0)
			continue
		}
		if n > m {
			mod := n % m
			n = mod
			fmt.Fprintln(writer, min(m-n, n))
		} else {
			fmt.Fprintln(writer, min(m-n, n))
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
