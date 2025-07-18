package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Solver struct {
	in  *bufio.Reader
	out *bufio.Writer
}

func NewSolver(in *bufio.Reader, out *bufio.Writer) *Solver {
	return &Solver{in: in, out: out}
}

func (s *Solver) solve() {
	var h, w int
	fmt.Fscan(s.in, &h, &w)
	c := make([][]byte, h+2)
	for i := range c {
		c[i] = make([]byte, w+2)
	}
	for i := 1; i <= h; i++ {
		line := make([]byte, w)
		s.in.Read(line)
		for j := 1; j <= w; j++ {
			c[i][j] = line[j-1]
		}
	}
	if h == 1 && w == 1 {
		fmt.Fprintln(s.out, "No")
		return
	}
	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
			if c[i][j] == '#' && c[i-1][j] != '#' && c[i+1][j] != '#' &&
				c[i][j-1] != '#' && c[i][j+1] != '#' {
				fmt.Fprintln(s.out, "No")
				return
			}
		}
	}
	fmt.Fprintln(s.out, "Yes")
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solver := NewSolver(reader, writer)
	solver.solve()
}

// End of Code
