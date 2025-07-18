package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Scanner struct {
	reader *bufio.Reader
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{reader: bufio.NewReader(r)}
}

func (s *Scanner) Next() string {
	line, _ := s.reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func (s *Scanner) NextInt() int {
	line := s.Next()
	n, _ := strconv.Atoi(line)
	return n
}

func (s *Scanner) NextLong() int64 {
	line := s.Next()
	n, _ := strconv.ParseInt(line, 10, 64)
	return n
}

type Writer struct {
	writer *bufio.Writer
}

func NewWriter(w io.Writer) *Writer {
	return &Writer{writer: bufio.NewWriter(w)}
}

func (w *Writer) Print(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
	w.writer.Flush()
}

func (w *Writer) Println(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
	w.writer.Flush()
}

func (w *Writer) Close() error {
	return w.writer.Flush()
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

func solve(a, b, q int, s, t []int64, scanner *Scanner, writer *Writer) {
	s = append([]int64{-10000000000}, s...)
	s = append(s, 20000000000)
	t = append([]int64{-10000000000}, t...)
	t = append(t, 20000000000)
	for i := 0; i < q; i++ {
		x := scanner.NextLong()
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		writer.Println(min(
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
	scanner := NewScanner(os.Stdin)
	writer := NewWriter(os.Stdout)
	a := scanner.NextInt()
	b := scanner.NextInt()
	q := scanner.NextInt()
	s := make([]int64, a)
	for i := 0; i < a; i++ {
		s[i] = scanner.NextLong()
	}
	t := make([]int64, b)
	for i := 0; i < b; i++ {
		t[i] = scanner.NextLong()
	}
	solve(a, b, q, s, t, scanner, writer)
	writer.Close()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a ...int64) int64 {
	m := a[0]
	for _, v := range a[1:] {
		if v < m {
			m = v
		}
	}
	return m
}

// End of Code
