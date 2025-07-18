package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	reader *bufio.Reader
}

func NewLightScanner(in *os.File) *LightScanner {
	return &LightScanner{reader: bufio.NewReader(in)}
}

func (ls *LightScanner) String() string {
	line, _ := ls.reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

func (ls *LightScanner) Ints() int {
	line := ls.String()
	n, _ := strconv.Atoi(line)
	return n
}

func (ls *LightScanner) Longs() int64 {
	line := ls.String()
	n, _ := strconv.ParseInt(line, 10, 64)
	return n
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(out *os.File) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(out)}
}

func (lw *LightWriter) Print(c string) {
	lw.writer.WriteString(c)
}

func (lw *LightWriter) Ans(s string) {
	lw.Print(s)
}

func (lw *LightWriter) Ansln(n int64) {
	lw.Ans(fmt.Sprintf("%d\n", n))
}

func (lw *LightWriter) Close() {
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

func solve(a, b, q int, s, t []int64, in *LightScanner, out *LightWriter) {
	s = append(s, -10000000000)
	s = append(s, 20000000000)
	t = append(t, -10000000000)
	t = append(t, 20000000000)
	for i := 0; i < q; i++ {
		x := in.Longs()
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		out.Ansln(min(
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
	in := NewLightScanner(os.Stdin)
	out := NewLightWriter(os.Stdout)
	a := in.Ints()
	b := in.Ints()
	q := in.Ints()
	s := make([]int64, a)
	t := make([]int64, b)
	for i := 0; i < a; i++ {
		s[i] = in.Longs()
	}
	for i := 0; i < b; i++ {
		t[i] = in.Longs()
	}
	solve(a, b, q, s, t, in, out)
	out.Close()
}

// End of Code
