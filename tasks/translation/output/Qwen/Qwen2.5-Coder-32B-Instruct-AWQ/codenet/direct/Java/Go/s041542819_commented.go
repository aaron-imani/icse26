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

	solver := DLazyFaith{}
	solver.solve(1, in, out)
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
		sl := x - s[Max(0, lowerBound(s, x+1)-1)]
		tl := x - t[Max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		out.Anslnt(Min(
			Max(sl, tl),
			Max(sr, tr),
			2*sl+tr,
			2*tl+sr,
			sl+2*tr,
			tl+2*sr,
		))
	}
}

type LightScanner struct {
	reader    *bufio.Reader
	tokenizer *strings.FieldsFunc
}

func NewLightScanner(r *os.File) *LightScanner {
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
		line, _, err := l.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer += string(line)
		if !strings.HasSuffix(buffer, "\n") {
			break
		}
	}
	return &strings.FieldsFunc(buffer, func(r rune) bool {
		return r == ' ' || r == '\t' || r == '\n'
	})
}

func (l *LightScanner) Ints() int {
	return mustAtoi(l.String())
}

func (l *LightScanner) Longs() int64 {
	return mustAtoi64(l.String())
}

func mustAtoi(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

func mustAtoi64(s string) int64 {
	i, err := strconv.ParseInt(s, 10, 64)
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

func NewLightWriter(w *os.File) *LightWriter {
	return &LightWriter{
		out: bufio.NewWriter(w),
	}
}

func (l *LightWriter) Print(c byte) {
	l.out.WriteByte(c)
	l.breaked = false
}

func (l *LightWriter) Prints(s string) {
	l.out.WriteString(s)
	l.breaked = false
}

func (l *LightWriter) Ans(s string) {
	if !l.breaked {
		l.Print(' ')
	}
	l.Prints(s)
}

func (l *LightWriter) Anslnt(n ...int64) {
	for _, n1 := range n {
		l.Ans(strconv.FormatInt(n1, 10))
		l.Ln()
	}
}

func (l *LightWriter) Ln() {
	l.Prints("\n")
	l.breaked = true
	if l.autoflush {
		l.out.Flush()
	}
}

func (l *LightWriter) Close() {
	l.out.Flush()
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Min(a ...int64) int64 {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
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

// End of Code
