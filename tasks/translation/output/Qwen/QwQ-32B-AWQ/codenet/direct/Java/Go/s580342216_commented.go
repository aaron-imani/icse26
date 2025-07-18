package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Solution struct {
	scanner *bufio.Scanner
}

func NewSolution() *Solution {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	return &Solution{scanner}
}

func (s *Solution) runCase() {
	line := s.scanner.Text()
	fields := strings.Fields(line)
	N, _ := strconv.Atoi(fields[0])
	K, _ := strconv.Atoi(fields[1])

	len := 0
	n := N
	for n > 0 {
		n /= K
		len++
	}
	fmt.Println(len)
}

func main() {
	sol := NewSolution()
	for sol.scanner.Scan() {
		sol.runCase()
	}
}

type LCS struct {
	dp [][]int
}

func (l *LCS) lcs(A, B string) int {
	m := len(A)
	n := len(B)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for i := 0; i <= m; i++ {
		dp[i][0] = 0
	}
	for j := 0; j <= n; j++ {
		dp[0][j] = 0
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if A[i-1] == B[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	l.dp = dp
	return dp[m][n]
}

func (l *LCS) getLCS(A, B string) string {
	m := len(A)
	n := len(B)
	index := l.dp[m][n]
	temp := index
	lcs := make([]byte, temp)
	i, j := m, n
	for i > 0 && j > 0 {
		if A[i-1] == B[j-1] {
			lcs[index-1] = A[i-1]
			i--
			j--
			index--
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

// End of Code
