package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(sc)))
	Q, _ := strconv.Atoi(strings.TrimSpace(readLine(sc)))
	s := readLine(sc)
	pre := make([]int, N+1)

	for i := 1; i < N; i++ {
		if s[i-1] == 'A' && s[i] == 'C' {
			pre[i] = 1
		}
	}

	for i := 1; i < N; i++ {
		pre[i] += pre[i-1]
	}

	for Q > 0 {
		l, _ := strconv.Atoi(strings.TrimSpace(readLine(sc)))
		r, _ := strconv.Atoi(strings.TrimSpace(readLine(sc)))
		r--
		fmt.Println(pre[r] - pre[l-1])
		Q--
	}
}

func readLine(sc *bufio.Reader) string {
	line, _ := sc.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

// End of Code
