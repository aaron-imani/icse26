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
	H := s.nextInt()
	W := s.nextInt()
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 0; i < H; i++ {
		line := s.nextString()
		for j, c := range line {
			C[i+1][j+1] = c
		}
	}
	if H == 1 && W == 1 {
		s.println("No")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' &&
				C[i][j-1] != '#' && C[i][j+1] != '#' {
				s.println("No")
				return
			}
		}
	}
	s.println("Yes")
}

func (s *Solver) nextInt() int {
	line := s.nextString()
	i, _ := strconv.Atoi(line)
	return i
}

func (s *Solver) nextLong() int64 {
	line := s.nextString()
	i, _ := strconv.ParseInt(line, 10, 64)
	return i
}

func (s *Solver) nextDouble() float64 {
	line := s.nextString()
	i, _ := strconv.ParseFloat(line, 64)
	return i
}

func (s *Solver) nextString() string {
	for {
		line, _, err := s.in.ReadLine()
		if err != nil {
			panic(err)
		}
		str := strings.TrimSpace(string(line))
		if len(str) > 0 {
			return str
		}
	}
}

func (s *Solver) println(a ...interface{}) {
	fmt.Fprintln(s.out, a...)
}

func (s *Solver) print(a ...interface{}) {
	fmt.Fprint(s.out, a...)
}

// End of Code
