package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	newSolution()
}

func newSolution() {
	var scanner *strings.Reader
	scanner = strings.NewReader(strings.NewReader(""))

	for scanner != nil {
		runCase(scanner)
	}
}

func runCase(scanner *strings.Reader) {
	line, _ := scanner.ReadString('\n')
	N, _ := strconv.Atoi(strings.Split(line, " ")[0])
	K, _ := strconv.Atoi(strings.Split(line, " ")[1])

	len := 0
	for N > 0 {
		N /= K
		len++
	}

	fmt.Println(len)
	return
}

func strToIntArray(str string) []int {
	vals := strings.Split(str, " ")
	res := make([]int, len(vals))
	for i, val := range vals {
		res[i], _ = strconv.Atoi(val)
	}
	return res
}

func lcs(A string, B string) int {
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

	return dp[szA][szB]
}

func getLCS(X string, Y string) string {
	m := len(X)
	n := len(Y)
	index := lcs(X, Y)
	temp := index

	lcs := make([]byte, index+1)
	lcs[index] = '\0'

	i := m
	j := n
	for i > 0 && j > 0 {
		if X[i-1] == Y[j-1] {
			lcs[index-1] = X[i-1]
			i--
			j--
			index--
		} else if lcs(X[:i-1], Y) > lcs(X, Y[:j-1]) {
			i--
		} else {
			j--
		}
	}

	return string(lcs[:temp+2])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
