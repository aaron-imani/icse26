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
	m := len(A)
	n := len(B)
	l.dp = make([][]int, m+1)
	for i := range l.dp {
		l.dp[i] = make([]int, n+1)
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

func (l *LCS) GetLCS(X, Y string) string {
	m := len(X)
	n := len(Y)
	var lcs []byte
	i, j := m, n
	for i > 0 && j > 0 {
		if X[i-1] == Y[j-1] {
			lcs = append(lcs, X[i-1])
			i--
			j--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	// Reverse the lcs slice to get the correct order
	for left, right := 0, len(lcs)-1; left < right; left, right = left+1, right-1 {
		lcs[left], lcs[right] = lcs[right], lcs[left]
	}
	return string(lcs)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		if len(parts) < 2 {
			continue
		}
		N, err := strconv.Atoi(parts[0])
		if err != nil {
			continue
		}
		K, err := strconv.Atoi(parts[1])
		if err != nil {
			continue
		}
		len := 0
		n := N
		for n > 0 {
			n /= K
			len++
		}
		fmt.Println(len)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}
}

// End of Code
