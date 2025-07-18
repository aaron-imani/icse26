package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Solver struct {
	in  *MyInput
	out *bufio.Writer
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
		for j, char := range line {
			C[i+1][j+1] = char
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

func (s *Solver) prr(str string) {
	s.out.WriteString(str)
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(reader *bufio.Reader) *MyInput {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanBytes) // Read byte by byte
	return &MyInput{scanner}
}

func (m *MyInput) nextString() string {
	var line strings.Builder
	for m.scanner.Scan() {
		char := m.scanner.Text()
		if char == "\n" {
			break
		}
		line.WriteString(char)
	}
	return line.String()
}

func (m *MyInput) nextInt() int {
	str := m.nextString()
	num, _ := strconv.Atoi(str)
	return num
}

func (m *MyInput) nextLong() int64 {
	str := m.nextString()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func (m *MyInput) nextDouble() float64 {
	str := m.nextString()
	num, _ := strconv.ParseFloat(str, 64)
	return num
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	in := NewMyInput(reader)
	solver := &Solver{in: in, out: writer}
	solver.solve()
}

// End of Code
