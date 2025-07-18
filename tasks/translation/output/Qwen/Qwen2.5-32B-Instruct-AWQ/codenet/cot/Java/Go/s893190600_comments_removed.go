package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type MyInput struct {
	sc *bufio.Scanner
}

func NewMyInput(r *bufio.Reader) *MyInput {
	return &MyInput{sc: bufio.NewScanner(r)}
}

func (mi *MyInput) nextInt() int {
	mi.sc.Scan()
	return atoi(mi.sc.Text())
}

func (mi *MyInput) nextLong() int64 {
	mi.sc.Scan()
	return atoI64(mi.sc.Text())
}

func (mi *MyInput) nextDouble() float64 {
	mi.sc.Scan()
	return atof(mi.sc.Text())
}

func (mi *MyInput) nextString() string {
	mi.sc.Scan()
	return mi.sc.Text()
}

type Solver struct {
	in  *MyInput
	out *bufio.Writer
}

func NewSolver(in *MyInput, out *bufio.Writer) *Solver {
	return &Solver{in: in, out: out}
}

func (s *Solver) solve() {
	H := s.in.nextInt()
	W := s.in.nextInt()
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 0; i < H; i++ {
		c := []rune(s.in.nextString())
		for j := 0; j < W; j++ {
			C[i+1][j+1] = c[j]
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

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
	writer := bufio.NewWriterSize(os.Stdout, 1024*1024)
	defer writer.Flush()
	mi := NewMyInput(reader)
	solver := NewSolver(mi, writer)
	solver.solve()
}

func atoi(s string) int {
	i, _ := fmt.Sscanf(s, "%d", new(int))
	return i
}

func atoI64(s string) int64 {
	i, _ := fmt.Sscanf(s, "%d", new(int64))
	return i
}

func atof(s string) float64 {
	f, _ := fmt.Sscanf(s, "%f", new(float64))
	return f
}

// End of Code
