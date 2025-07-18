package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var in = bufio.NewScanner(os.Stdin)
	var out = bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}

func solve(in *bufio.Scanner, out *bufio.Writer) {
	n, _ := strconv.Atoi(readLine(in))
	a := make([][]rune, n)
	for i := range a {
		a[i] = []rune(readLine(in))
	}

	P, Q := int64(37), int64(47)
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0], powQ[0] = 1, 1
	for i := int64(1); i <= int64(n); i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	hashRow := make([][]int64, n)
	hashCol := make([][]int64, n)
	for i := range hashRow {
		hashRow[i] = make([]int64, n)
		hashCol[i] = make([]int64, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				hashRow[i][k] += int64(a[i][j]) * powP[(j-k+n)%n]
				hashCol[j][k] += int64(a[i][j]) * powP[(i-k+n)%n]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				if hashRow[(i+A)%n][B] != hashCol[(i+B)%n][A] {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}

func readLine(in *bufio.Scanner) string {
	in.Scan()
	return strings.TrimSpace(in.Text())
}

// End of Code
