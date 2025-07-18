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
	tokenizer *strings.Reader
	tokens    []string
}

func NewLightScanner(r *bufio.Reader) *LightScanner {
	return &LightScanner{reader: r}
}

func (ls *LightScanner) nextToken() string {
	if len(ls.tokens) == 0 {
		var line string
		var err error
		if line, err = ls.reader.ReadString('\n'); err != nil {
			panic(err)
		}
		ls.tokens = strings.Fields(line)
	}
	token := ls.tokens[0]
	ls.tokens = ls.tokens[1:]
	return token
}

func (ls *LightScanner) String() string {
	return ls.nextToken()
}

func (ls *LightScanner) Int() int {
	token := ls.nextToken()
	num, err := strconv.Atoi(token)
	if err != nil {
		panic(err)
	}
	return num
}

func (ls *LightScanner) Long() int64 {
	token := ls.nextToken()
	num, err := strconv.ParseInt(token, 10, 64)
	if err != nil {
		panic(err)
	}
	return num
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w *bufio.Writer) *LightWriter {
	return &LightWriter{writer: w}
}

func (lw *LightWriter) Print(s string) {
	lw.writer.WriteString(s)
}

func (lw *LightWriter) Println(s string) {
	lw.writer.WriteString(s + "\n")
}

func (lw *LightWriter) Ans(s string) {
	lw.Print(s)
}

func (lw *LightWriter) Ansln(n int64) {
	lw.Ans(strconv.FormatInt(n, 10))
	lw.Println("")
}

func (lw *LightWriter) Close() {
	lw.writer.Flush()
}

type DLazyFaith struct{}

func (d *DLazyFaith) solve(testNumber int, in *LightScanner, out *LightWriter) {
	a := in.Int()
	b := in.Int()
	q := in.Int()
	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0], t[0] = -10000000000, -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.Long()
	}
	for i := 0; i < b; i++ {
		t[i+1] = in.Long()
	}
	s[a+1], t[b+1] = 20000000000, 20000000000
	for i := 0; i < q; i++ {
		x := in.Long()
		sl := x - s[lowerBound(s, x+1)-1]
		tl := x - t[lowerBound(t, x+1)-1]
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
	for _, v := range values {
		if v < minValue {
			minValue = v
		}
	}
	return minValue
}

func max(values ...int64) int64 {
	maxValue := values[0]
	for _, v := range values {
		if v > maxValue {
			maxValue = v
		}
	}
	return maxValue
}

func main() {
	in := NewLightScanner(bufio.NewReader(os.Stdin))
	out := NewLightWriter(bufio.NewWriter(os.Stdout))
	defer out.Close()
	solver := &DLazyFaith{}
	solver.solve(1, in, out)
}
// End of Code
