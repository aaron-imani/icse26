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

var (
	ii     = NewInputIterator()
	convStr = map[int]string{
		8: " ",
		9: "\n",
		0: "",
	}
)

func next() string {
	return ii.Next()
}

func hasNext() bool {
	return ii.HasNext()
}

func nextInt() int {
	s := next()
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

func nextIntArray() []int {
	s := next()
	parts := strings.Split(s, convStr[8])
	result := make([]int, len(parts))
	for i, part := range parts {
		result[i], _ = strconv.Atoi(part)
	}
	return result
}

func main() {
	solve()
}

func solve() {
	N := nextInt()
	list := nextIntArray()
	max := 0
	output := 0
	for _, num := range list {
		if max <= num {
			max = num
			output++
		}
	}
	fmt.Println(output)
}
// End of Code
