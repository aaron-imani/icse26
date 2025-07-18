package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(reader *bufio.Reader) *MyInput {
	return &MyInput{scanner: bufio.NewScanner(reader)}
}

func (m *MyInput) nextInt() int {
	m.scanner.Scan()
	num, _ := strconv.Atoi(m.scanner.Text())
	return num
}

func solve(testNumber int, in *MyInput, out *bufio.Writer) {
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	in := NewMyInput(reader)
	solve(1, in, writer)
	// End of Code
