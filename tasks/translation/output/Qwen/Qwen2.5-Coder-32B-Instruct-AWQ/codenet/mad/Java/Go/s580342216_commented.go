package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Solution struct {
	scanner *bufio.Scanner
}

func NewSolution() {
	s := &Solution{
		scanner: bufio.NewScanner(os.Stdin),
	}
	for s.scanner.Scan() {
		s.runCase()
	}
}

func (s *Solution) runCase() {
	line := s.scanner.Text()
	parts := strings.Fields(line)
	N, _ := strconv.Atoi(parts[0])
	K, _ := strconv.Atoi(parts[1])

	len := 0
	for N > 0 {
		N /= K
		len++
	}

	fmt.Println(len)
}

func main() {
	NewSolution()
}

// End of Code
