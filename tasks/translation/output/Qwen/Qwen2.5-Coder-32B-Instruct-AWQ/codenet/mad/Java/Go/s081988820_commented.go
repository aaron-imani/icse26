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
	in     *bufio.Scanner
	buffer []string
}

func NewScanner(r *os.File) *Scanner {
	sc := &Scanner{in: bufio.NewScanner(r)}
	sc.in.Buffer(make([]byte, 1024), 1024) // Set buffer size to 1024 bytes
	sc.in.Split(bufio.ScanWords)
	return sc
}

func (s *Scanner) next() string {
	if len(s.buffer) == 0 {
		s.in.Scan()
		s.buffer = strings.Fields(s.in.Text())
	}
	ret := s.buffer[0]
	s.buffer = s.buffer[1:]
	return ret
}

func (s *Scanner) nextInt() int {
	i, _ := strconv.Atoi(s.next())
	return i
}

// End of Code
