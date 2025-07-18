package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(inputStream *os.File) *MyInput {
	return &MyInput{bufio.NewScanner(inputStream)}
}

func (in *MyInput) next() string {
	in.scanner.Scan()
	return in.scanner.Text()
}

func (in *MyInput) nextInt() int {
	i, _ := strconv.Atoi(in.next())
	return i
}

func (in *MyInput) nextString() string {
	return in.next()
}

type Solver struct {
	in  *MyInput
	out *bufio.Writer
}

func NewSolver(in *MyInput, out *bufio.Writer) *Solver {
	return &Solver{in, out}
}

func (s *Solver) solve() {
	H := s.in.nextInt()
	W := s.in.nextInt()
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 0; i < H; i++ {
		line := s.in.nextString()
		for j, c := range line {
			C[i+1][j+1] = c
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

func (s *Solver) prn(str string) {
	s.out.WriteString(str + "\n")
}

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewMyInput(inputStream)
	out := bufio.NewWriter(outputStream)
	defer out.Flush()

	solver := NewSolver(in, out)
	solver.solve()
}

// End of Code
