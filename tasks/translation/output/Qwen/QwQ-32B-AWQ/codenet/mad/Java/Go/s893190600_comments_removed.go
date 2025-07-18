package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type MyInput struct {
	sc *bufio.Scanner
}

func NewMyInput(r io.Reader) *MyInput {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &MyInput{sc}
}

func (m *MyInput) NextInt() int {
	m.sc.Scan()
	n, _ := strconv.Atoi(m.sc.Text())
	return n
}

func (m *MyInput) NextString() string {
	m.sc.Scan()
	return m.sc.Text()
}

type Solver struct {
	in  *MyInput
	out *bufio.Writer
}

func (s *Solver) Solve() {
	H := s.in.NextInt()
	W := s.in.NextInt()
	const pad = 2
	grid := make([][]byte, H+pad)
	for i := range grid {
		grid[i] = make([]byte, W+pad)
	}
	for i := 0; i < H; i++ {
		line := s.in.NextString()
		for j := 0; j < W; j++ {
			grid[i+1][j+1] = line[j]
		}
	}
	if H == 1 && W == 1 {
		fmt.Fprint(s.out, "No\n")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if grid[i][j] == '#' && grid[i-1][j] != '#' && grid[i+1][j] != '#' &&
				grid[i][j-1] != '#' && grid[i][j+1] != '#' {
				fmt.Fprint(s.out, "No\n")
				return
			}
		}
	}
	fmt.Fprint(s.out, "Yes\n")
}

func main() {
	in := NewMyInput(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solver := &Solver{in: in, out: out}
	solver.Solve()
	out.Flush()
}
// End of Code
