package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	input    = bufio.NewScanner(os.Stdin)
	output   = bufio.NewWriter(os.Stdout)
	convStr  = map[int]string{8: " ", 9: "\n", 0: ""}
	inputBuf []string
	inputIdx int
)

func main() {
	input.Split(bufio.ScanLines)
	solve()
	output.Flush()
}

func solve() {
	N := nextInt()
	list := nextIntArray()
	max := 0
	output := 0
	for i := 0; i < N; i++ {
		if max <= list[i] {
			max = list[i]
			output++
		}
	}
	fmt.Fprintln(output, output)
}

func next() string {
	if inputIdx >= len(inputBuf) {
		if !input.Scan() {
			return ""
		}
		inputBuf = strings.Split(input.Text(), convStr[8])
		inputIdx = 0
	}
	val := inputBuf[inputIdx]
	inputIdx++
	return val
}

func nextInt() int {
	i, _ := strconv.Atoi(next())
	return i
}

func nextIntArray() []int {
	strs := nextStrArray()
	ints := make([]int, len(strs))
	for i, s := range strs {
		ints[i], _ = strconv.Atoi(s)
	}
	return ints
}

func nextStrArray() []string {
	return strings.Split(next(), convStr[8])
}
// End of Code
