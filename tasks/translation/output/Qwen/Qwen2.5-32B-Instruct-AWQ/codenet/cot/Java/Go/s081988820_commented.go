package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner(r *bufio.Reader) *Scanner {
	return &Scanner{sc: bufio.NewScanner(r)}
}

func (s *Scanner) Int() int {
	s.sc.Scan()
	num, _ := strconv.Atoi(s.sc.Text())
	return num
}

func solve() {
	sc := NewScanner(bufio.NewReader(os.Stdin))
	H := sc.Int()
	W := sc.Int()
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			c[i][j] = sc.Int()
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
			A := sc.Int()
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
	solve()
}
// End of Code
