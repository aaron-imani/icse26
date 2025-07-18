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
	r *bufio.Reader
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{r: bufio.NewReader(r)}
}

func (s *Scanner) next() string {
	var buf strings.Builder
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == '\n' || b == ' ' {
			break
		}
		buf.WriteByte(b)
	}
	return buf.String()
}

func (s *Scanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

// End of Code
