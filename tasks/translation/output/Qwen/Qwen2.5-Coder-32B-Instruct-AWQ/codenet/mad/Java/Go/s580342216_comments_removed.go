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
	scanner := bufio.NewScanner(os.Stdin)
	solution := Solution{scanner}
	for scanner.Scan() {
		solution.run_case()
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
	}
}

func (s *Solution) run_case() {
	line := s.scanner.Text()
	parts := strings.Split(line, " ")
	N, errN := strconv.Atoi(parts[0])
	K, errK := strconv.Atoi(parts[1])
	if errN != nil || errK != nil {
		fmt.Fprintln(os.Stderr, "Error parsing input:", errN, errK)
		return
	}

	length := 0
	for N > 0 {
		N /= K
		length++
	}

	fmt.Println(length)
}

func (s *Solution) strToIntArray(str string) []int {
	vals := strings.Split(str, " ")
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
	sz_a := len(A)
	sz_b := len(B)
	l.dp = make([][]int, sz_a+1)
	for i := range l.dp {
		l.dp[i] = make([]int, sz_b+1)
	}

	for i := 0; i <= sz_a; i++ {
		l.dp[i][0] = 0
	}
	for j := 0; j <= sz_b; j++ {
		l.dp[0][j] = 0
	}

	for i := 1; i <= sz_a; i++ {
		for j := 1; j <= sz_b; j++ {
			if A[i-1] == B[j-1] {
				l.dp[i][j] = l.dp[i-1][j-1] + 1
			} else {
				l.dp[i][j] = max(l.dp[i-1][j], l.dp[i][j-1])
			}
		}
	}

	return l.dp[sz_a][sz_b]
}

func (l *LCS) getLCS(X, Y string) string {
	m := len(X)
	n := len(Y)

	index := l.dp[m][n]
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

	return string(lcs)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
