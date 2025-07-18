package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := Solver{in: in, out: out}
	solver.solve()
}

type Solver struct {
	in  *bufio.Reader
	out *bufio.Writer
}

func (s *Solver) solve() {
	H := s.ni()
	W := s.ni()
	C := make([][]byte, H+2)
	for i := range C {
		C[i] = make([]byte, W+2)
	}
	for i := 0; i < H; i++ {
		line := s.ns()
		for j := 0; j < W; j++ {
			C[i+1][j+1] = line[j]
		}
	}
	if H == 1 && W == 1 {
		s.prn("No")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' &&
				C[i][j-1] != '#' && C[i][j+1] != '#' {
				s.prn("No")
				return
			}
		}
	}
	s.prn("Yes")
}

func (s *Solver) prn(x string) {
	fmt.Fprintln(s.out, x)
}

func (s *Solver) ni() int {
	i, _ := strconv.Atoi(strings.TrimSpace(s.ns()))
	return i
}

func (s *Solver) ns() string {
	line, _ := s.in.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

// End of Code
