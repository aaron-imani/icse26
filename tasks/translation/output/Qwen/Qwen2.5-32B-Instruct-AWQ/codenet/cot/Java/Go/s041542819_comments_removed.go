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

func NewLightScanner(in io.Reader) *LightScanner {
	return &LightScanner{reader: bufio.NewReader(in)}
}

func (ls *LightScanner) String() string {
	line, _ := ls.reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func (ls *LightScanner) Ints() int {
	return parseInt(ls.String())
}

func (ls *LightScanner) Longs() int64 {
	return parseLong(ls.String())
}

func parseInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func parseLong(s string) int64 {
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(out io.Writer) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(out)}
}

func (lw *LightWriter) Print(c rune) {
	lw.writer.WriteRune(c)
}

func (lw *LightWriter) Print(s string) {
	lw.writer.WriteString(s)
}

func (lw *LightWriter) Ans(s string) {
	if !lw.breaked {
		lw.Print(' ')
	}
	lw.Print(s)
}

func (lw *LightWriter) Ansln(n int64) {
	lw.Ans(fmt.Sprintf("%d", n)).Ln()
}

func (lw *LightWriter) Ln() {
	lw.writer.WriteString("\n")
	lw.breaked = true
	lw.writer.Flush()
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
	min, max := 0, len(a)
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

type DLazyFaith struct{}

func (d *DLazyFaith) Solve(testNumber int, in *LightScanner, out *LightWriter) {
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

func main() {
	in := NewLightScanner(os.Stdin)
	out := NewLightWriter(os.Stdout)
	solver := &DLazyFaith{}
	solver.Solve(1, in, out)
	out.Close()
}

// End of Code
