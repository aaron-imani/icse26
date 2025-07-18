package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var input []string
var index int

func readInput() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input = append(input, scanner.Text())
	}
}

func hasNext() bool {
	return index < len(input)
}

func next() string {
	if hasNext() {
		defer func() { index++ }()
		return input[index]
	}
	panic("There is no more input")
}

func nextInt() int {
	n, _ := strconv.Atoi(next())
	return n
}

func nextLong() int64 {
	n, _ := strconv.ParseInt(next(), 10, 64)
	return n
}

func nextDouble() float64 {
	n, _ := strconv.ParseFloat(next(), 64)
	return n
}

func nextStrArray() []string {
	return split(next(), " ")
}

func nextCharArray() []string {
	return split(next(), "")
}

func nextIntArray() []int {
	arr := nextStrArray()
	intArr := make([]int, len(arr))
	for i, s := range arr {
		intArr[i], _ = strconv.Atoi(s)
	}
	return intArr
}

func nextLongArray() []int64 {
	arr := nextStrArray()
	longArr := make([]int64, len(arr))
	for i, s := range arr {
		longArr[i], _ = strconv.ParseInt(s, 10, 64)
	}
	return longArr
}

func split(str string, sep string) []string {
	return fmt.Sprintf("%s", str).Split(sep, -1)
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
	fmt.Println(output)
}

func main() {
	input = make([]string, 0)
	readInput()
	solve()
}
// End of Code
