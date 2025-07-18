package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewLightScanner(os.Stdin)
	out := NewLightWriter(os.Stdout)
	defer out.Close()

	solver := &DLazyFaith{}
	solver.solve(1, in, out)
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
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		out.Ansl(min(
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

func min(values ...int64) int64 {
	minValue := values[0]
	for _, v := range values {
		if v < minValue {
			minValue = v
		}
	}
	return minValue
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

type LightScanner struct {
	reader    *bufio.Reader
	tokenizer *strings.FieldsFunc
}

func NewLightScanner(r io.Reader) *LightScanner {
	return &LightScanner{
		reader: bufio.NewReader(r),
	}
}

func (l *LightScanner) next() string {
	if l.tokenizer == nil {
		l.tokenizer = func() []string {
			line, _, _ := l.reader.ReadLine()
			return strings.FieldsFunc(string(line), func(r rune) bool {
				return r == ' ' || r == '\t' || r == '\n'
			})
		}
	}
	if len(*l.tokenizer) == 0 {
		*l.tokenizer = l.tokenizer()
	}
	token := (*l.tokenizer)[0]
	*l.tokenizer = (*l.tokenizer)[1:]
	return token
}

func (l *LightScanner) String() string {
	return l.next()
}

func (l *LightScanner) Int() int {
	i, _ := strconv.Atoi(l.String())
	return i
}

func (l *LightScanner) Long() int64 {
	i, _ := strconv.ParseInt(l.String(), 10, 64)
	return i
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(w)}
}

func (l *LightWriter) Print(a interface{}) {
	fmt.Fprint(l.writer, a)
}

func (l *LightWriter) Println(a interface{}) {
	fmt.Fprintln(l.writer, a)
}

func (l *LightWriter) Ans(a interface{}) {
	if a != "" {
		l.Print(" ")
	}
	l.Print(a)
}

func (l *LightWriter) Ansl(a ...interface{}) {
	for _, v := range a {
		l.Ans(v)
	}
	l.Println("")
}

func (l *LightWriter) Close() {
	l.writer.Flush()
}

// End of Code
