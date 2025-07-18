package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 1; i <= H; i++ {
		line := s.nextLine()
		for j := 1; j <= W; j++ {
			C[i][j] = rune(line[j-1])
		}
	}
	if H == 1 && W == 1 {
		fmt.Fprintln(s.out, "No")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' && C[i][j-1] != '#' && C[i][j+1] != '#' {
				fmt.Fprintln(s.out, "No")
				return
			}
		}
	}
	fmt.Fprintln(s.out, "Yes")
}

func (s *Solver) nextLine() string {
	line, _ := s.in.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solver := NewSolver(reader, writer)
	solver.solve()
}
// End of Code
