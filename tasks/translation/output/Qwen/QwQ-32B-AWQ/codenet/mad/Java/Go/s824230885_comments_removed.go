package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var inputs []string
var inputIndex int

func next() string {
	s := inputs[inputIndex]
	inputIndex++
	return s
}

func hasNext() bool {
	return inputIndex < len(inputs)
}

func nextInt() int {
	s := next()
	n, _ := strconv.Atoi(s)
	return n
}

func nextStrArray() []string {
	s := next()
	return strings.Fields(s)
}

func nextIntArray() []int {
	parts := nextStrArray()
	res := make([]int, len(parts))
	for i, s := range parts {
		res[i], _ = strconv.Atoi(s)
	}
	return res
}

func solve() {
	N := nextInt()
	arr := nextIntArray()
	if N == 0 {
		fmt.Println(0)
		return
	}
	max := arr[0]
	output := 1
	for i := 1; i < N; i++ {
		if arr[i] >= max {
			max = arr[i]
			output++
		}
	}
	fmt.Println(output)
}

func main() {
	inputs = make([]string, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		inputs = append(inputs, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	solve()
}
// End of Code
