package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type DLazyFaith struct{}

func (d *DLazyFaith) solve(testNumber int, in *LightScanner, out *LightWriter) {
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

type LightScanner struct {
	reader *bufio.Reader
}

func NewLightScanner(in *os.File) *LightScanner {
	return &LightScanner{reader: bufio.NewReader(in)}
}

func (l *LightScanner) String() string {
	line, err := l.reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(line)
}

func (l *LightScanner) Ints() int {
	return parseInt(l.String())
}

func (l *LightScanner) Longs() int64 {
	return parseLong(l.String())
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(out *os.File) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(out)}
}

func (l *LightWriter) Print(s string) {
	_, err := l.writer.WriteString(s)
	if err != nil {
		panic(err)
	}
}

func (l *LightWriter) Ans(s string) {
	l.Print(s)
}

func (l *LightWriter) Ansln(n int64) {
	l.Ans(fmt.Sprintf("%d\n", n))
}

func (l *LightWriter) Close() {
	err := l.writer.Flush()
	if err != nil {
		panic(err)
	}
}

func parseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return n
}

func parseLong(s string) int64 {
	n, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic(err)
	}
	return n
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

func main() {
	in := NewLightScanner(os.Stdin)
	out := NewLightWriter(os.Stdout)
	solver := &DLazyFaith{}
	solver.solve(1, in, out)
	out.Close()
}

// End of Code
