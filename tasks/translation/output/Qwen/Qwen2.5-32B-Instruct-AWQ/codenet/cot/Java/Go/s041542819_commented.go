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
	lw.Print(s)
}

func (lw *LightWriter) Ansln(n int64) {
	lw.Ans(fmt.Sprintf("%d\n", n))
}

func (lw *LightWriter) Close() {
	lw.writer.Flush()
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

func min(values ...int64) int64 {
	minValue := values[0]
	for _, v := range values[1:] {
		if v < minValue {
			minValue = v
		}
	}
	return minValue
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
	solver := &DLazyFaith{}
	solver.Solve(1, in, out)
	out.Close()
}
// End of Code
