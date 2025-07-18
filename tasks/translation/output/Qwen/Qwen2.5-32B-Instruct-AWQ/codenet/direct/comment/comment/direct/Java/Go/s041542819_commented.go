package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type lightScanner struct {
	reader *bufio.Reader
}

func newLightScanner(in io.Reader) *lightScanner {
	return &lightScanner{reader: bufio.NewReader(in)}
}

func (ls *lightScanner) string() string {
	line, _ := ls.reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func (ls *lightScanner) ints() int {
	s := ls.string()
	n, _ := strconv.Atoi(s)
	return n
}

func (ls *lightScanner) longs() int64 {
	s := ls.string()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

type lightWriter struct {
	writer *bufio.Writer
}

func newLightWriter(out io.Writer) *lightWriter {
	return &lightWriter{writer: bufio.NewWriter(out)}
}

func (lw *lightWriter) print(s string) {
	lw.writer.WriteString(s)
}

func (lw *lightWriter) ans(s string) {
	lw.print(" ")
	lw.print(s)
}

func (lw *lightWriter) ansln(n ...int64) {
	for _, n1 := range n {
		lw.ans(fmt.Sprintf("%d", n1))
		lw.ln()
	}
}

func (lw *lightWriter) ln() {
	lw.print("\n")
}

func (lw *lightWriter) close() {
	lw.writer.Flush()
}

func min(v ...int64) int64 {
	minVal := v[0]
	for _, val := range v[1:] {
		if val < minVal {
			minVal = val
		}
	}
	return minVal
}

func lowerBound(a []int64, t int64) int {
	min := 0
	max := len(a)
	for min < max {
		mid := (min + max) / 2
		if t <= a[mid] {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

func solve(testNumber int, in *lightScanner, out *lightWriter) {
	a := in.ints()
	b := in.ints()
	q := in.ints()
	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0] = -10000000000
	t[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.longs()
	}
	for i := 0; i < b; i++ {
		t[i+1] = in.longs()
	}
	s[a+1] = 20000000000
	t[b+1] = 20000000000
	for i := 0; i < q; i++ {
		x := in.longs()
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		out.ansln(min(
			max(sl, tl),
			max(sr, tr),
			2*sl+tr,
			2*tl+sr,
			sl+2*tr,
			tl+2*sr,
		))
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	in := newLightScanner(os.Stdin)
	out := newLightWriter(os.Stdout)
	solve(1, in, out)
	out.close()
}
// End of Code
