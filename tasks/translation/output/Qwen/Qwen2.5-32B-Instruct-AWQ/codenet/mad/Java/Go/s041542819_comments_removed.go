package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	reader *bufio.Reader
}

func NewLightScanner(r io.Reader) *LightScanner {
	return &LightScanner{reader: bufio.NewReader(r)}
}

func (ls *LightScanner) String() string {
	s, _ := ls.reader.ReadString('\n')
	return strings.TrimSpace(s)
}

func (ls *LightScanner) Ints() int {
	s := ls.String()
	n, _ := strconv.Atoi(s)
	return n
}

func (ls *LightScanner) Longs() int64 {
	s := ls.String()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(w)}
}

func (lw *LightWriter) Print(c string) {
	lw.writer.WriteString(c)
}

func (lw *LightWriter) Ansln(n int64) {
	lw.Print(fmt.Sprintf("%d\n", n))
}

func (lw *LightWriter) Close() {
	lw.writer.Flush()
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

func min(v ...int64) int64 {
	minVal := math.MaxInt64
	for _, val := range v {
		if val < minVal {
			minVal = val
		}
	}
	return minVal
}

func solve(a, b, q int, s, t []int64, in *LightScanner, out *LightWriter) {
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
	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0] = -10000000000
	t[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.Longs()
	}
	for i := 0; i < b; i++ {
		t[i+1] = in.Longs()
	}
	s[a+1] = 20000000000
	t[b+1] = 20000000000
	solve(a, b, q, s, t, in, out)
	out.Close()
}
// End of Code
