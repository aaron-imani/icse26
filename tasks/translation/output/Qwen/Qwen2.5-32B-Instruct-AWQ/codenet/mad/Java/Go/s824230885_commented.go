package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)


type InputIterator struct {
	inputLine []string
	index     int
	max       int
}

func NewInputIterator() *InputIterator {
	inputIterator := &InputIterator{
		inputLine: make([]string, 0, 1024),
		index:     0,
		max:       0,
	}
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		inputIterator.inputLine = append(inputIterator.inputLine, scanner.Text())
	}
	inputIterator.max = len(inputIterator.inputLine)
	return inputIterator
}

func (ii *InputIterator) HasNext() bool {
	return ii.index < ii.max
}

func (ii *InputIterator) Next() string {
	if ii.HasNext() {
		result := ii.inputLine[ii.index]
		ii.index++
		return result
	}
	panic("There is no more input")
}

func nextInt(ii *InputIterator) int {
	n, err := strconv.Atoi(ii.Next())
	if err != nil {
		panic("Invalid integer input")
	}
	return n
}

func nextIntArray(ii *InputIterator) []int {
	input := strings.Fields(ii.Next())
	result := make([]int, len(input))
	for i, s := range input {
		n, err := strconv.Atoi(s)
		if err != nil {
			panic("Invalid integer input")
		}
		result[i] = n
	}
	return result
}

func solve(ii *InputIterator) {
	N := nextInt(ii)
	list := nextIntArray(ii)
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
	ii := NewInputIterator()
	solve(ii)
}
// End of Code
