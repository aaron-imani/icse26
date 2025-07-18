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
	reader := bufio.NewReader(os.Stdin)
	inputLine := make([]string, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}
		inputLine = append(inputLine, strings.TrimSpace(line))
	}
	return &InputIterator{
		inputLine: inputLine,
		index:     0,
		max:       len(inputLine),
	}
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
	return strconv.Atoi(ii.Next())
}

func nextIntArray(ii *InputIterator) []int {
	input := strings.Fields(ii.Next())
	result := make([]int, len(input))
	for i, s := range input {
		result[i], _ = strconv.Atoi(s)
	}
	return result
}

func solve() {
	ii := NewInputIterator()
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
	solve()
}
// End of Code
