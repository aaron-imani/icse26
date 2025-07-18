package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	scanner *bufio.Scanner
}

func NewLightScanner(r io.Reader) *LightScanner {
	s := bufio.NewScanner(r)
	s.Split(bufio.ScanWords)
	return &LightScanner{scanner: s}
}

func (ls *LightScanner) Next() string {
	if !ls.scanner.Scan() {
		return ""
	}
	return ls.scanner.Text()
}

func (ls *LightScanner) Int() int {
	s := ls.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (ls *LightScanner) Long() int64 {
	s := ls.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(w)}
}

func (lw *LightWriter) Println(a ...interface{}) {
	fmt.Fprintln(lw.writer, a...)
}

func (lw *LightWriter) Flush() {
	_ = lw.writer.Flush()
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

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(vals ...int64) int64 {
	m := vals[0]
	for _, v := range vals[1:] {
		if v < m {
			m = v
		}
	}
	return m
}

func main() {
	in := NewLightScanner(os.Stdin)
	out := NewLightWriter(os.Stdout)
	defer out.Flush()

	a := in.Int()
	b := in.Int()
	q := in.Int()

	s := make([]int64, a+2)
	s[0] = -10000000000
	s[a+1] = 20000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.Long()
	}

	t := make([]int64, b+2)
	t[0] = -10000000000
	t[b+1] = 20000000000
	for i := 0; i < b; i++ {
		t[i+1] = in.Long()
	}

	for i := 0; i < q; i++ {
		x := in.Long()
		lbS := lowerBound(s, x+1)
		slIndex := lbS - 1
		if slIndex < 0 {
			slIndex = 0
		}
		sl := x - s[slIndex]

		lbT := lowerBound(t, x+1)
		tlIndex := lbT - 1
		if tlIndex < 0 {
			tlIndex = 0
		}
		tl := x - t[tlIndex]

		lbS2 := lowerBound(s, x)
		sr := s[lbS2] - x

		lbT2 := lowerBound(t, x)
		tr := t[lbT2] - x

		val1 := max(sl, tl)
		val2 := max(sr, tr)
		val3 := 2*sl + tr
		val4 := 2*tl + sr
		val5 := sl + 2*tr
		val6 := tl + 2*sr

		minVal := min(val1, val2, val3, val4, val5, val6)
		out.Println(minVal)
	}
}

// End of Code
