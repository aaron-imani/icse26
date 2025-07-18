package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		N, _ := strconv.Atoi(parts[0])
		K, _ := strconv.Atoi(parts[1])

		length := 0
		n := N
		for n > 0 {
			n /= K
			length++
		}
		fmt.Println(length)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}

type LCS struct {
	dp [][]int
}

func (l *LCS) LCSLength(A string, B string) int {
	m := len(A)
	n := len(B)
	l.dp = make([][]int, m+1)
	for i := range l.dp {
		l.dp[i] = make([]int, n+1)
	}

	for i := 0; i <= m; i++ {
		l.dp[i][0] = 0
	}
	for j := 0; j <= n; j++ {
		l.dp[0][j] = 0
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if A[i-1] == B[j-1] {
				l.dp[i][j] = l.dp[i-1][j-1] + 1
			} else {
				l.dp[i][j] = max(l.dp[i-1][j], l.dp[i][j-1])
			}
		}
	}
	return l.dp[m][n]
}

func (l *LCS) GetLCS(A string, B string) string {
	m := len(A)
	n := len(B)
	index := l.dp[m][n]
	temp := index

	lcs := make([]byte, index)
	i, j := m, n
	for i > 0 && j > 0 {
		if A[i-1] == B[j-1] {
			lcs[index-1] = byte(A[i-1])
			index--
			i--
			j--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	return string(lcs)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func strToIntArray(s string) []int {
	parts := strings.Fields(s)
	res := make([]int, len(parts))
	for i, p := range parts {
		res[i], _ = strconv.Atoi(p)
	}
	return res
}

// End of Code
