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
	var H, W int
	fmt.Fscan(s.in, &H, &W)
	C := make([][]byte, H+2)
	for i := range C {
		C[i] = make([]byte, W+2)
	}
	for i := 1; i <= H; i++ {
		fmt.Fscan(s.in, &C[i][1:W+1])
	}
	if H == 1 && W == 1 {
		fmt.Fprintln(s.out, "No")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' &&
				C[i][j-1] != '#' && C[i][j+1] != '#' {
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
