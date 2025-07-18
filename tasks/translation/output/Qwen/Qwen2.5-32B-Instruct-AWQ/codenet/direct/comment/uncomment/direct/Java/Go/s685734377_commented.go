package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type taskB struct{}

func (t *taskB) solve(n int, in *fastScanner, out *bufio.Writer) {
	p := int64(37)
	q := int64(47)
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0] = 1
	powQ[0] = 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * p
		powQ[i] = powQ[i-1] * q
	}

	a := make([][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = []rune(in.nextLine())
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
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

type fastScanner struct {
	scanner *bufio.Scanner
}

func newFastScanner(r io.Reader) *fastScanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	return &fastScanner{scanner: s}
}

func (fs *fastScanner) nextLine() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *fastScanner) nextInt() int {
	fs.scanner.Scan()
	num, _ := strconv.Atoi(fs.scanner.Text())
	return num
}

func main() {
	in := newFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	n := in.nextInt()
	t := &taskB{}
	t.solve(n, in, out)
}

// End of Code
