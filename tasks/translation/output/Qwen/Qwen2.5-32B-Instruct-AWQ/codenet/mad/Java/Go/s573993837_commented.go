package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(sc *bufio.Reader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		t--
		n, _ := strconv.ParseInt(read(sc), 10, 64)
		m, _ := strconv.ParseInt(read(sc), 10, 64)
		if n == 0 || n == m {
			pw.WriteString("0\n")
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
		}
		pw.WriteString(fmt.Sprintf("%d\n", min(m-n, n)))
	}
}

func read(sc *bufio.Reader) string {
	line, _ := sc.ReadString('\n')
	return strings.TrimSpace(line)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewReader(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()
	solve(sc, pw)
}
// End of Code
