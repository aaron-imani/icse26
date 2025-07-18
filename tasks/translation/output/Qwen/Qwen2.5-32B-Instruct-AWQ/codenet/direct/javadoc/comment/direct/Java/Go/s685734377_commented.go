package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type taskB struct{}

func (t *taskB) solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscanln(in, &n)
	a := make([][]rune, n)
	for i := range a {
		a[i] = []rune(strings.TrimSpace(readLine(in)))
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
				hashRow[i][k] += int64(a[i][j]) * powP[int64((j-k+n)%n)]
				hashCol[j][k] += int64(a[i][j]) * powP[int64((i-k+n)%n)]
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
	out.Flush()
}

func readLine(r *bufio.Reader) string {
	line, _ := r.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solver := &taskB{}
	solver.solve(in, out)
}
// End of Code
