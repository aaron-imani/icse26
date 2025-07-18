package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type LCS struct {
	dp [][]int
}

func (l *LCS) LCSLength(A, B string) int {
	a := []rune(A)
	b := []rune(B)
	m := len(a)
	n := len(b)
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
			if a[i-1] == b[j-1] {
				l.dp[i][j] = l.dp[i-1][j-1] + 1
			} else {
				l.dp[i][j] = max(l.dp[i-1][j], l.dp[i][j-1])
			}
		}
	}
	return l.dp[m][n]
}

func (l *LCS) GetLCS(A, B string) string {
	a := []rune(A)
	b := []rune(B)
	m := len(a)
	n := len(b)
	index := l.dp[m][n]
	temp := index
	runes := make([]rune, temp)
	i, j := m, n
	for i > 0 && j > 0 {
		if a[i-1] == b[j-1] {
			runes[temp-index] = a[i-1]
			i--
			j--
			index--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	return string(runes[:temp])
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		N, _ := strconv.Atoi(fields[0])
		K, _ := strconv.Atoi(fields[1])

		length := 0
		n := N
		for n > 0 {
			length++
			n /= K
		}
		fmt.Println(length)
	}
}
// End of Code
