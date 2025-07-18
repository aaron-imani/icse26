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
	return &Solution{
		scanner: bufio.NewScanner(os.Stdin),
	}
}

func (s *Solution) Run() {
	for s.scanner.Scan() {
		s.runCase()
	}
}

func (s *Solution) runCase() {
	line := s.scanner.Text()
	parts := strings.Split(line, " ")
	N, err := strconv.Atoi(parts[0])
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing N: %v\n", err)
		return
	}
	K, err := strconv.Atoi(parts[1])
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error parsing K: %v\n", err)
		return
	}

	len := 0
	for N > 0 {
		N /= K
		len++
	}

	fmt.Println(len)
}

func (s *Solution) strToIntArray(str string) []int {
	parts := strings.Split(str, " ")
	res := make([]int, len(parts))
	for i, part := range parts {
		res[i], _ = strconv.Atoi(part)
	}
	return res
}

type LCS struct {
	dp [][]int
}

func (l *LCS) LCS(A string, B string) int {
	szA := len(A)
	szB := len(B)
	dp := make([][]int, szA+1)
	for i := range dp {
		dp[i] = make([]int, szB+1)
	}

	for i := 0; i <= szA; i++ {
		dp[i][0] = 0
	}
	for j := 0; j <= szB; j++ {
		dp[0][j] = 0
	}

	for i := 1; i <= szA; i++ {
		for j := 1; j <= szB; j++ {
			if A[i-1] == B[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	l.dp = dp
	return dp[szA][szB]
}

func (l *LCS) GetLCS(X string, Y string) string {
	m := len(X)
	n := len(Y)
	index := l.dp[m][n]
	temp := index

	lcs := make([]byte, index+1)
	lcs[index] = 0

	i := m
	j := n
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

	return string(lcs[:temp+1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	solution := NewSolution()
	solution.Run()
}
// End of Code
