package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	t := 1
	for ; t > 0; t-- {
		var n, m int64
		fmt.Fscan(in, &n, &m)
		if n == 0 {
			fmt.Fprintln(out, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(out, 0)
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Fprintln(out, min(m-n, n))
			continue
		}
		fmt.Fprintln(out, min(m-n, n))
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
// End of Code
