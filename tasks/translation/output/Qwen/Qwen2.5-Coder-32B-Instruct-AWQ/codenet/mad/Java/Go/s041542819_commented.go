package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	reader    *bufio.Reader
	tokenizer []string
}

func NewLightScanner(r *bufio.Reader) *LightScanner {
	return &LightScanner{reader: r}
}

func (ls *LightScanner) string() string {
	if len(ls.tokenizer) == 0 {
		line, _, err := ls.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		ls.tokenizer = strings.Fields(string(line))
	}
	token := ls.tokenizer[0]
	ls.tokenizer = ls.tokenizer[1:]
	return token
}

func (ls *LightScanner) ints() int {
	i, err := strconv.Atoi(ls.string())
	if err != nil {
		panic(err)
	}
	return i
}

func (ls *LightScanner) longs() int64 {
	i, err := strconv.ParseInt(ls.string(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w *bufio.Writer) *LightWriter {
	return &LightWriter{writer: w}
}

func (lw *LightWriter) print(s string) {
	_, err := lw.writer.WriteString(s)
	if err != nil {
		panic(err)
	}
}

func (lw *LightWriter) ans(s string) {
	lw.print(s)
}

func (lw *LightWriter) ansln(n ...int64) {
	for _, num := range n {
		lw.ans(fmt.Sprintf("%d", num))
		lw.ln()
	}
}

func (lw *LightWriter) ln() {
	lw.print("\n")
}

func (lw *LightWriter) close() {
	err := lw.writer.Flush()
	if err != nil {
		panic(err)
	}
}

func min(values ...int64) int64 {
	minValue := values[0]
	for _, v := range values {
		if v < minValue {
			minValue = v
		}
	}
	return minValue
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
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

func (d *DLazyFaith) solve(testNumber int, in *LightScanner, out *LightWriter) {
	a, b, q := in.ints(), in.ints(), in.ints()
	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0], t[0] = -10000000000, -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.longs()
	}
	for i := 0; i < b; i++ {
		t[i+1] = in.longs()
	}
	s[a+1], t[b+1] = 20000000000, 20000000000
	for i := 0; i < q; i++ {
		x := in.longs()
		sl := x - s[max(0, int64(lowerBound(s, x+1)-1))]
		tl := x - t[max(0, int64(lowerBound(t, x+1)-1))]
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

func main() {
	in := NewLightScanner(bufio.NewReader(os.Stdin))
	out := NewLightWriter(bufio.NewWriter(os.Stdout))
	defer out.close()
	solver := &DLazyFaith{}
	solver.solve(1, in, out)
}

// End of Code
