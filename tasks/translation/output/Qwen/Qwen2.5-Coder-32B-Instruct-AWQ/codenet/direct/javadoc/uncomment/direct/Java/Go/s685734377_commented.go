package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := readInt(in)
	P := int64(37)
	Q := int64(47)
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0], powQ[0] = 1, 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	a := make([][]byte, n)
	for i := range a {
		a[i] = []byte(readString(in))
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
				hashRow[i][k] += int64(a[i][j]) * powP[mod(j-k+n, n)]
				hashCol[j][k] += int64(a[i][j]) * powP[mod(i-k+n, n)]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				if hashRow[mod(i+A, n)][B] != hashCol[mod(i+B, n)][A] {
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

func mod(x, y int) int {
	return (x + y) % y
}

func readInt(r *bufio.Reader) int {
	line, _ := r.ReadString('\n')
	line = strings.TrimSpace(line)
	v, _ := strconv.Atoi(line)
	return v
}

func readString(r *bufio.Reader) string {
	line, _ := r.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

// End of Code
