package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
}

type MyInput struct {
	sc *bufio.Scanner
}

func NewMyInput(r *bufio.Reader) *MyInput {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &MyInput{sc: sc}
}

func (m *MyInput) nextInt() int {
	m.sc.Scan()
	num, _ := strconv.Atoi(m.sc.Text())
	return num
}

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	outputWriter := bufio.NewWriter(os.Stdout)
	myInput := NewMyInput(inputReader)
	solver := &Solver{}
	solver.solve(1, myInput, outputWriter)
	outputWriter.Flush()
}
// End of Code
