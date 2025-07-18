package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Solution struct to handle input and calculations
type Solution struct{}

// runCase processes each input line
func (s *Solution) runCase(line string) {
	parts := strings.Fields(line)
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	len := 0
	for N > 0 {
		N /= K
		len++
	}
	fmt.Println(len)
}

// main function reads input lines and processes each case
func main() {
	sol := Solution{}
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		sol.runCase(line)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintf(os.Stderr, "reading input: %v", err)
	}
}

// LCS struct for Longest Common Subsequence
type LCS struct {
	dp [][]int
}

// LcsLength computes the length of LCS using DP
func (l *LCS) LcsLength(a string, b string) int {
	m := len(a)
	n := len(b)
	l.dp = make([][]int, m+1)
	for i := range l.dp {
		l.dp[i] = make([]int, n+1)
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

// GetLCS reconstructs the LCS string from the DP table
func (l *LCS) GetLCS(x string, y string) string {
	m := len(x)
	n := len(y)
	index := l.dp[m][n]
	lcs := make([]byte, index)
	i, j := m, n
	for i > 0 && j > 0 {
		if x[i-1] == y[j-1] {
			lcs[index-1] = x[i-1]
			i--
			j--
			index--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}
	return string(l.gpu is not responding properlylcs)
}

// max returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// End of Code
