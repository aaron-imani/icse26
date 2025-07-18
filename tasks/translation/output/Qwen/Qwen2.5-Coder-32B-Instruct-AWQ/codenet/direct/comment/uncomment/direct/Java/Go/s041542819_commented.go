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
	buf       []string
}

func NewLightScanner(r io.Reader) *LightScanner {
	return &LightScanner{
		reader: bufio.NewReader(r),
	}
}

func (s *LightScanner) next() string {
	if len(s.buf) == 0 {
		line, _, err := s.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		s.buf = strings.FieldsFunc(string(line), func(r rune) bool {
			return r == ' ' || r == '\t' || r == '\n'
		})
	}
	token := s.buf[0]
	s.buf = s.buf[1:]
	return token
}

func (s *LightScanner) String() string {
	return s.next()
}

func (s *LightScanner) Ints() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *LightScanner) Longs() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
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

func (w *LightWriter) Print(c byte) *LightWriter {
	w.out.WriteByte(c)
	w.breaked = false
	return w
}

func (w *LightWriter) PrintString(s string) *LightWriter {
	w.out.WriteString(s)
	w.breaked = false
	return w
}

func (w *LightWriter) Ans(s string) *LightWriter {
	if !w.breaked {
		w.Print(' ')
	}
	return w.PrintString(s)
}

func (w *LightWriter) AnsInt(i int) *LightWriter {
	return w.Ans(strconv.Itoa(i))
}

func (w *LightWriter) AnsInt64(i int64) *LightWriter {
	return w.Ans(strconv.FormatInt(i, 10))
}

func (w *LightWriter) Ansln(n ...int64) *LightWriter {
	for _, n1 := range n {
		w.AnsInt64(n1).Ln()
	}
	return w
}

func (w *LightWriter) Ln() *LightWriter {
	w.Print('\n')
	w.breaked = true
	if w.autoflush {
		w.out.Flush()
	}
	return w
}

func (w *LightWriter) close() {
	w.out.Flush()
}

// End of Code
