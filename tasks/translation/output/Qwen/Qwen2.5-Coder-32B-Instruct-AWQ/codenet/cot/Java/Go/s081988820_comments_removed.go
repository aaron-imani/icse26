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
				if min[i] > c[i][j]+min[j] {
					min[i] = c[i][j] + min[j]
				}
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

type Scanner struct {
	r *bufio.Reader
}

func NewScanner(r *os.File) *Scanner {
	return &Scanner{bufio.NewReader(r)}
}

func (s *Scanner) nextInt() int {
	line := s.nextLine()
	i, _ := strconv.Atoi(line)
	return i
}

func (s *Scanner) nextLine() string {
	line, _, _ := s.r.ReadLine()
	return strings.TrimSpace(string(line))
}

// End of Code
