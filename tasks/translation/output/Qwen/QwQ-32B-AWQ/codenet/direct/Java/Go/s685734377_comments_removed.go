package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner(r io.Reader) *FastScanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &FastScanner{sc}
}

func (fs *FastScanner) Next() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

func (fs *FastScanner) NextInt() int {
	n, _ := strconv.Atoi(fs.Next())
	return n
}

type TaskB struct{}

func (t *TaskB) Solve(testNumber int, in *FastScanner, out *bufio.Writer) {
	n := in.NextInt()
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		line := in.Next()
		a[i] = []byte(line)
	}

	const P = 37
	const Q = 47
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0] = 1
	powQ[0] = 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * int64(P)
		powQ[i] = powQ[i-1] * int64(Q)
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
				jMinusK := (j - k + n) % n
				hashRow[i][k] += int64(a[i][j]) * powP[jMinusK]
				iMinusK := (i - k + n) % n
				hashCol[j][k] += int64(a[i][j]) * powP[iMinusK]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				rowI := (i + A) % n
				colI := (i + B) % n
				hr := hashRow[rowI][B]
				hc := hashCol[colI][A]
				if hr != hc {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
}

func main() {
	in := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	task := new(TaskB)
	task.Solve(1, in, out)
}

// End of Code
