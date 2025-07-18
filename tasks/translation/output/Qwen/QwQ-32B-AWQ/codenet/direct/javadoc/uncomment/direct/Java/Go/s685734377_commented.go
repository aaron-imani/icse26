package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	scanner *bufio.Scanner
	tokens  []string
	current int
}

func NewFastScanner(r io.Reader) *FastScanner {
	fs := &FastScanner{
		scanner: bufio.NewScanner(r),
		tokens:  make([]string, 0),
	}
	fs.scanner.Split(bufio.ScanWords)
	return fs
}

func (fs *FastScanner) Next() string {
	if fs.current < len(fs.tokens) {
		token := fs.tokens[fs.current]
		fs.current++
		return token
	}
	if !fs.scanner.Scan() {
		return ""
	}
	fs.tokens = strings.Fields(fs.scanner.Text())
	fs.current = 1
	return fs.tokens[0]
}

func (fs *FastScanner) NextInt() int {
	s := fs.Next()
	n, _ := strconv.Atoi(s)
	return n
}

type TaskB struct{}

func NewTaskB() *TaskB {
	return &TaskB{}
}

func (t *TaskB) solve(in *FastScanner, out *bufio.Writer) {
	n := in.NextInt()
	grid := make([][]byte, n)
	for i := 0; i < n; i++ {
		s := in.Next()
		grid[i] = []byte(s)
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
			for k := : 0; k < n; k++ {
				deltaRow := (j - k + n) % n
				termRow := int64(grid[i][j]) * powP[deltaRow]
				hashRow[i][k] += termRow

				deltaCol := (i - k + n) % n
				termCol := int64(grid[i][j]) * powP[deltaCol]
				hashCol[j][k] += termCol
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				rowIdx := (i + A) % n
				colIdx := (i + B) % n
				if hashRow[rowIdx][B] != hashCol[colIdx][A] {
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

func main() {
	scanner := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	taskB := NewTaskB()
	taskB.solve(scanner, out)
	out.Flush()
}

// End of Code
