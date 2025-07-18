package main

import (
	"fmt"
	"os"
	"strconv"
)

var sc = NewScanner(os.Stdin)

func NewScanner(r *os.File) *Scanner {
	return &Scanner{r: r}
}

type Scanner struct {
	r   *os.File
	buf []byte
	p   int
}

func (s *Scanner) Next() string {
	if s.p >= len(s.buf) {
		s.load()
	}
	if s.p >= len(s.buf) {
		return ""
	}
	start := s.p
	for s.p < len(s.buf) && s.buf[s.p] != ' ' && s.buf[s.p] != '\n' {
		s.p++
	}
	return string(s.buf[start:s.p])
}

func (s *Scanner) load() {
	var n int
	s.buf, n = make([]byte, 1024), 0
	for {
		var nn int
		nn, _ = s.r.Read(s.buf[n:])
		n += nn
		if n == 0 || s.buf[n-1] == '\n' {
			break
		}
	}
	s.buf = s.buf[:n]
	s.p = 0
}

func (s *Scanner) NextInt() int {
	i, _ := strconv.Atoi(s.Next())
	return i
}

func (s *Scanner) HasNext() bool {
	if s.p >= len(s.buf) {
		s.load()
	}
	return s.p < len(s.buf)
}

var d int

func read() bool {
	if !sc.HasNext() {
		return false
	}
	d = sc.NextInt()
	return true
}

func solve() int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	for read() {
		fmt.Println(solve())
	}
}
// End of Code
