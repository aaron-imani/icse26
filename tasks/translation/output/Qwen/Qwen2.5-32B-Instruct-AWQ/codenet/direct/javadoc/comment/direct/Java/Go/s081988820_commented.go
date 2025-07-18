package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner(reader *bufio.Reader) *Scanner {
	return &Scanner{scanner: bufio.NewScanner(reader)}
}

func (s *Scanner) NextInt() int {
	s.scanner.Scan()
	num, _ := strconv.Atoi(s.scanner.Text())
	return num
}

func (s *Scanner) NextLong() int64 {
	s.scanner.Scan()
	num, _ := strconv.ParseInt(s.scanner.Text(), 10, 64)
	return num
}

func (s *Scanner) NextDouble() float64 {
	s.scanner.Scan()
	num, _ := strconv.ParseFloat(s.scanner.Text(), 64)
	return num
}

func (s *Scanner) NextString() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func solve(scanner *Scanner) {
	H := scanner.NextInt()
	W := scanner.NextInt()
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			c[i][j] = scanner.NextInt()
		}
	}
	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}
	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				min[i] = minInt(min[i], c[i][j]+min[j])
			}
		}
	}
	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			A := scanner.NextInt()
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	scanner := NewScanner(reader)
	solve(scanner)
}
// End of Code
