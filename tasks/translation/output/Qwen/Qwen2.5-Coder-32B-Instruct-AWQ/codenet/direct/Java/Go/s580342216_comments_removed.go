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

func main() {
	solution := Solution{scanner: bufio.NewScanner(os.Stdin)}
	for solution.scanner.Scan() {
		solution.run_case()
	}
}

func (s *Solution) run_case() {
	line := s.scanner.Text()
	parts := strings.Fields(line)
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	length := 0
	for N > 0 {
		N /= K
		length++
	}

	fmt.Println(length)
}

func strToIntArray(str string) []int {
	vals := strings.Fields(str)
	sz := len(vals)
	res := make([]int, sz)
	for i := 0; i < sz; i++ {
		res[i], _ = strconv.Atoi(vals[i])
	}
	return res
}

type LCS struct {
	dp [][]int
}

func (l *LCS) lcs(A, B string) int {
	szA, szB := len(A), len(B)
	l.dp = make([][]int, szA+1)
	for i := range l.dp {
		l.dp[i] = make([]int, szB+1)
	}

	for i := 0; i <= szA; i++ {
		l.dp[i][0] = 0
	}
	for j := 0; j <= szB; j++ {
		l.dp[0][j] = 0
	}

	for i := 1; i <= szA; i++ {
		for j := 1; j <= szB; j++ {
			if A[i-1] == B[j-1] {
				l.dp[i][j] = l.dp[i-1][j-1] + 1
			} else {
				l.dp[i][j] = max(l.dp[i-1][j], l.dp[i][j-1])
			}
		}
	}

	return l.dp[szA][szB]
}

func (l *LCS) getLCS(X, Y string) string {
	m, n := len(X), len(Y)

	index := l.dp[m][n]
	temp := index

	lcs := make([]byte, index)
	i, j := m, n
	for i > 0 && j > 0 {
		if X[i-1] == Y[j-1] {
			lcs[index-1] = X[i-1]
			i--
			j--
			index--
		} else if l.dp[i-1][j] > l.dp[i][j-1] {
			i--
		} else {
			j--
		}
	}

	return string(lcs[:temp])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
