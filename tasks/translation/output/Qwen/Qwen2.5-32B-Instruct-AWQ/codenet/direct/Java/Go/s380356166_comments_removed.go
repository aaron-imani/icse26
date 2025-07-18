package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Solver struct{}

func (s *Solver) solve(testNumber int, in *MyInput, out *bufio.Writer) {
	ans := 0
	K := in.nextInt()
	S := in.nextInt()
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
	out.Flush()
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(reader *bufio.Reader) *MyInput {
	return &MyInput{scanner: bufio.NewScanner(reader)}
}

func (in *MyInput) nextInt() int {
	in.scanner.Scan()
	num, _ := strconv.Atoi(strings.TrimSpace(in.scanner.Text()))
	return num
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	myInput := NewMyInput(reader)
	solver := &Solver{}
	solver.solve(1, myInput, writer)
}

// End of Code
