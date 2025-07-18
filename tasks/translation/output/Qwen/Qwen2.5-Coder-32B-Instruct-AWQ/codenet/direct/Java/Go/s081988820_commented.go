package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	main := Main{}
	main.solve()
}

type Main struct{}

func (m *Main) solve() {
	sc := NewScanner(os.Stdin)
	H := sc.nextInt()
	W := sc.nextInt()
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
		for j := range c[i] {
			c[i][j] = sc.nextInt()
		}
	}
	min := make([]int, 10)
	for i := range min {
		min[i] = c[i][1]
	}
	for tc := 0; tc < 10; tc++ {
		for i := range min {
			for j := range c[i] {
				min[i] = minInt(min[i], c[i][j]+min[j])
			}
		}
	}
	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			A := sc.nextInt()
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Scanner struct {
	sc        *bufio.Scanner
	buf       []string
	index     int
	buffer    []byte
	isPrinted bool
}

func NewScanner(r *os.File) *Scanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &Scanner{sc: sc}
}

func (s *Scanner) next() string {
	if len(s.buf) == 0 {
		s.sc.Scan()
		s.buf = strings.Split(s.sc.Text(), " ")
		s.index = 0
	}
	ret := s.buf[s.index]
	s.index++
	return ret
}

func (s *Scanner) nextInt() int {
	n, _ := strconv.Atoi(s.next())
	return n
}

func (s *Scanner) nextLong() int64 {
	n, _ := strconv.ParseInt(s.next(), 10, 64)
	return n
}

func (s *Scanner) nextFloat() float64 {
	n, _ := strconv.ParseFloat(s.next(), 64)
	return n
}

// End of Code
