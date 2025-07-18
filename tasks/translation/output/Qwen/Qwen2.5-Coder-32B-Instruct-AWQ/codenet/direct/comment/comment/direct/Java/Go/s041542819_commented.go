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
	solver.Solve(1, in, out)
}

type DLazyFaith struct{}

func (d *DLazyFaith) Solve(testNumber int, in *LightScanner, out *LightWriter) {
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

func (l *LightScanner) String() string {
	if l.tokenizer == nil {
		l.tokenizer = l.nextTokenizer()
	}
	if len(*l.tokenizer) == 0 {
		*l.tokenizer = l.nextTokenizer()
	}
	token := (*l.tokenizer)[0]
	*l.tokenizer = (*l.tokenizer)[1:]
	return token
}

func (l *LightScanner) nextTokenizer() []string {
	var buffer strings.Builder
	for {
		line, isPrefix, err := l.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer.Write(line)
		if !isPrefix {
			break
		}
	}
	return strings.FieldsFunc(buffer.String(), func(r rune) bool {
		return r == ' ' || r == '\t' || r == '\n'
	})
}

func (l *LightScanner) Int() int {
	i, err := strconv.Atoi(l.String())
	if err != nil {
		panic(err)
	}
	return i
}

func (l *LightScanner) Long() int64 {
	i, err := strconv.ParseInt(l.String(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{
		writer: bufio.NewWriter(w),
	}
}

func (l *LightWriter) Print(a interface{}) {
	_, err := fmt.Fprintf(l.writer, "%v", a)
	if err != nil {
		panic(err)
	}
}

func (l *LightWriter) Ansl(a ...interface{}) {
	for i, v := range a {
		if i > 0 {
			l.Print(" ")
		}
		l.Print(v)
	}
	l.Println()
}

func (l *LightWriter) Println() {
	l.Print("\n")
}

func (l *LightWriter) Close() {
	err := l.writer.Flush()
	if err != nil {
		panic(err)
	}
}

// End of Code
