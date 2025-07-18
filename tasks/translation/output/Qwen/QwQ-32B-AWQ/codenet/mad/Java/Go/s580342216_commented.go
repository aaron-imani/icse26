// Negative side's corrected code
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LCS struct {
	dp [][]int
}

func (l *LCS) LCSLength(a string, b string) int {
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

func (l *LCS) GetLCS(x string, y string) string {
	m := len(x)
	n := len(y)
	index := l.dp[m][n]
	lcs := make([]byte, 0, index)
	i, j := m, n
	for i > 0 && j > 0 {
		if x[i-1] == y[j-1] {
			lcs = append(lcs, x[i-1])
			i--
			j--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	// Reverse the collected characters
	for left, right := 0, len(lcs)-1; left < right; left, right = left+1, right-1 {
		lcs[left], lcs[right] = lcs[right], lcs[left]
	}
	return string(lcs)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		N, _ := strconv.Atoi(fields[0])
		K, _ := strconv.Atoi(fields[1])

		length := 0 // Renamed 'len' to 'length'
		n := N
		for n > 0 {
			n /= K
			length++
		}
		fmt.Println(length)
	}
}
// End of Code
