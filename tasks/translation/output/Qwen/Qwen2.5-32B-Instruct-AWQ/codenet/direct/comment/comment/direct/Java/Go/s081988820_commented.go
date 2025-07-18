package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Scanner struct {
	reader *bufio.Reader
}

func NewScanner(reader *bufio.Reader) *Scanner {
	return &Scanner{reader: reader}
}

func (s *Scanner) NextInt() int {
	num, _ := strconv.Atoi(s.Next())
	return num
}

func (s *Scanner) Next() string {
	line, _ := s.reader.ReadString('\n')
	return line[:len(line)-1]
}

func solve(sc *Scanner) {
	H := sc.NextInt()
	W := sc.NextInt()
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			c[i][j] = sc.NextInt()
		}
	}
	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}
	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				min[i] = Min(min[i], c[i][j]+min[j])
			}
		}
	}
	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			A := sc.NextInt()
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := NewScanner(bufio.NewReader(os.Stdin))
	solve(scanner)
}
// End of Code
