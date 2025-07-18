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
	ii := &InputIterator{}
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		ii.inputLine = append(ii.inputLine, scanner.Text())
	}
	ii.max = len(ii.inputLine)
	return ii
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
	next := ii.Next()
	num, _ := strconv.Atoi(next)
	return num
}

func nextIntArray(ii *InputIterator) []int {
	next := ii.Next()
	strs := strings.Split(next, " ")
	result := make([]int, len(strs))
	for i, str := range strs {
		result[i], _ = strconv.Atoi(str)
	}
	return result
}

func main() {
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
// End of Code
