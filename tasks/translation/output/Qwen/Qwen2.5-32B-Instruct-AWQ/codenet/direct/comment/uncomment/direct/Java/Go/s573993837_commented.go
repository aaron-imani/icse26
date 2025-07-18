package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(sc *bufio.Reader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n, _ := strconv.ParseInt(readLine(sc), 10, 64)
		m, _ := strconv.ParseInt(readLine(sc), 10, 64)
		if n == 0 {
			pw.WriteString("0\n")
			continue
		}
		if n == m {
			pw.WriteString("0\n")
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			pw.WriteString(fmt.Sprintf("%d\n", min(m-n, n)))
			continue
		}
		pw.WriteString(fmt.Sprintf("%d\n", min(m-n, n)))
		t--
	}
}

func readLine(sc *bufio.Reader) string {
	line, _ := sc.ReadString('\n')
	return line[:len(line)-1]
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
