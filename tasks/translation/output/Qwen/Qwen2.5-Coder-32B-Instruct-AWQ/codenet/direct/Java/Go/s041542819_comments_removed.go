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
	solver := DLazyFaith{}
	solver.solve(1, in, out)
	out.close()
}

type DLazyFaith struct{}

func (d *DLazyFaith) solve(testNumber int, in *LightScanner, out *LightWriter) {
	a := in.ints()
	b := in.ints()
	q := in.ints()
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
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
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

func (l *LightScanner) string() string {
	if l.tokenizer == nil {
		l.tokenizer = l.readTokens()
	}
	if len(*l.tokenizer) == 0 {
		*l.tokenizer = l.readTokens()
	}
	token := (*l.tokenizer)[0]
	*l.tokenizer = (*l.tokenizer)[1:]
	return token
}

func (l *LightScanner) readTokens() []string {
	var buffer string
	for {
		line, _, err := l.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer += string(line)
		if !strings.HasSuffix(buffer, "\n") {
			break
		}
	}
	return strings.FieldsFunc(buffer, func(r rune) bool {
		return r == ' ' || r == '\t' || r == '\n'
	})
}

func (l *LightScanner) ints() int {
	i, err := strconv.Atoi(l.string())
	if err != nil {
		panic(err)
	}
	return i
}

func (l *LightScanner) longs() int64 {
	i, err := strconv.ParseInt(l.string(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

type LightWriter struct {
	out       *bufio.Writer
	autoflush bool
	breaked   bool
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{
		out:     bufio.NewWriter(w),
		breaked: true,
	}
}

func (l *LightWriter) print(s string) *LightWriter {
	_, err := l.out.WriteString(s)
	if err != nil {
		panic(err)
	}
	l.breaked = false
	return l
}

func (l *LightWriter) ans(s string) *LightWriter {
	if !l.breaked {
		l.print(" ")
	}
	return l.print(s)
}

func (l *LightWriter) ansln(n ...int64) *LightWriter {
	for _, n1 := range n {
		l.ans(fmt.Sprintf("%d", n1)).ln()
	}
	return l
}

func (l *LightWriter) ln() *LightWriter {
	l.print("\n")
	l.breaked = true
	if l.autoflush {
		l.flush()
	}
	return l
}

func (l *LightWriter) flush() {
	err := l.out.Flush()
	if err != nil {
		panic(err)
	}
}

func (l *LightWriter) close() {
	err := l.out.Flush()
	if err != nil {
		panic(err)
	}
}

// End of Code
