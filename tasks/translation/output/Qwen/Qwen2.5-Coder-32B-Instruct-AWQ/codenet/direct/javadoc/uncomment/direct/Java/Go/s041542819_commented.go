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
	solver := &DLazyFaith{}
	solver.solve(1, in, out)
	out.close()
}

type DLazyFaith struct{}

func (d *DLazyFaith) solve(testNumber int, in *LightScanner, out *LightWriter) {
	a := in.Ints()
	b := in.Ints()
	q := in.Ints()
	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0], t[0] = -10000000000, -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = in.Longs()
	}
	for i := 0; i < b; i++ {
		t[i+1] = in.Longs()
	}
	s[a+1], t[b+1] = 20000000000, 20000000000
	for i := 0; i < q; i++ {
		x := in.Longs()
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

func max(values ...int64) int64 {
	maxValue := values[0]
	for _, v := range values {
		if v > maxValue {
			maxValue = v
		}
	}
	return maxValue
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
		l.tokenizer = l.nextTokens()
	}
	token := (*l.tokenizer)[0]
	*l.tokenizer = (*l.tokenizer)[1:]
	return token
}

func (l *LightScanner) nextTokens() *[]string {
	var buffer string
	for {
		line, isPrefix, err := l.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer += string(line)
		if !isPrefix {
			break
		}
	}
	return &strings.FieldsFunc(buffer, func(r rune) bool {
		return r == ' ' || r == '\t' || r == '\n'
	})
}

func (l *LightScanner) Ints() int {
	i, err := strconv.Atoi(l.String())
	if err != nil {
		panic(err)
	}
	return i
}

func (l *LightScanner) Longs() int64 {
	i, err := strconv.ParseInt(l.String(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

type LightWriter struct {
	out       *bufio.Writer
	autoFlush bool
	broke     bool
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{
		out: bufio.NewWriter(w),
	}
}

func (l *LightWriter) Print(c byte) *LightWriter {
	l.out.WriteByte(c)
	l.broke = false
	return l
}

func (l *LightWriter) Prints(s string) *LightWriter {
	l.out.WriteString(s)
	l.broke = false
	return l
}

func (l *LightWriter) Ans(s string) *LightWriter {
	if !l.broke {
		l.Print(' ')
	}
	return l.Prints(s)
}

func (l *LightWriter) Anslong(i int64) *LightWriter {
	return l.Ans(strconv.FormatInt(i, 10))
}

func (l *LightWriter) Anslongs(n ...int64) *LightWriter {
	for _, n1 := range n {
		l.Ans(n1).Ln()
	}
	return l
}

func (l *LightWriter) Ln() *LightWriter {
	l.Print('\n')
	l.broke = true
	if l.autoFlush {
		l.out.Flush()
	}
	return l
}

func (l *LightWriter) close() {
	l.out.Flush()
}

// End of Code
