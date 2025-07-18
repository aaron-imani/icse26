package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	mainInstance := Main{}
	mainInstance.solve()
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
	r *bufio.Reader
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewReader(r)}
}

func (s *Scanner) next() string {
	var buf []byte
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == ' ' || b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

func (s *Scanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *Scanner) nextLong() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (s *Scanner) nextFloat64() float64 {
	f, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

func (s *Scanner) nextLine() string {
	var buf []byte
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

func (s *Scanner) nextLines(n int) []string {
	lines := make([]string, n)
	for i := range lines {
		lines[i] = s.nextLine()
	}
	return lines
}

func (s *Scanner) nextInts(n int) []int {
	ints := make([]int, n)
	for i := range ints {
		ints[i] = s.nextInt()
	}
	return ints
}

func (s *Scanner) nextLongs(n int) []int64 {
	longs := make([]int64, n)
	for i := range longs {
		longs[i] = s.nextLong()
	}
	return longs
}

func (s *Scanner) nextFloat64s(n int) []float64 {
	floats := make([]float64, n)
	for i := range floats {
		floats[i] = s.nextFloat64()
	}
	return floats
}

func (s *Scanner) nextWords() []string {
	line := s.nextLine()
	return strings.Fields(line)
}

// End of Code
