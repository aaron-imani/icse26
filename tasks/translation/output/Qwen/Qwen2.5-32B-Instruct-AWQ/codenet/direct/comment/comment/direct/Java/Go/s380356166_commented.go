package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Solver struct{}

func (s *Solver) solve(testNumber int, in *MyInput, out *os.File) {
	ans := 0
	K := in.NextInt()
	S := in.NextInt()
	wk := 0
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk = S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	fmt.Fprintln(out, ans)
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(reader *bufio.Reader) *MyInput {
	return &MyInput{scanner: bufio.NewScanner(reader)}
}

func (mi *MyInput) NextInt() int {
	mi.scanner.Scan()
	num, _ := strconv.Atoi(mi.scanner.Text())
	return num
}

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	outputWriter := os.Stdout

	myInput := NewMyInput(inputReader)
	solver := Solver{}
	solver.solve(1, myInput, outputWriter)
}

// End of Code
