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
	return ""
}

var CONVSTR = map[int]string{
	8: " ",
	9: "\n",
	0: "",
}

var ii = NewInputIterator()

func flush() {
	// Flush operation in Go is not required for stdout
}

func myout(t interface{}) {
	fmt.Println(t)
}

func myerr(t interface{}) {
	fmt.Fprintf(os.Stderr, "debug: %v\n", t)
}

func next() string {
	return ii.Next()
}

func hasNext() bool {
	return ii.HasNext()
}

func nextInt() (int, error) {
	n, err := strconv.Atoi(next())
	return n, err
}

func nextLong() (int64, error) {
	n, err := strconv.ParseInt(next(), 10, 64)
	return n, err
}

func nextDouble() (float64, error) {
	n, err := strconv.ParseFloat(next(), 64)
	return n, err
}

func nextStrArray() []string {
	return strings.Fields(next())
}

func nextCharArray() []string {
	return strings.Split(next(), "")
}

func nextIntArray() ([]int, error) {
	input := nextStrArray()
	ret := make([]int, len(input))
	for i, s := range input {
		ret[i], _ = strconv.Atoi(s)
	}
	return ret, nil
}

func nextLongArray() ([]int64, error) {
	input := nextStrArray()
	ret := make([]int64, len(input))
	for i, s := range input {
		ret[i], _ = strconv.ParseInt(s, 10, 64)
	}
	return ret, nil
}

func myconv(list []string, no int) string {
	joinString := CONVSTR[no]
	return strings.Join(list, joinString)
}

func myconvStr(str string, no int) []string {
	splitString := CONVSTR[no]
	return strings.Split(str, splitString)
}

func solve() {
	N, _ := nextInt()
	list, _ := nextIntArray()
	max := 0
	output := 0
	for i := 0; i < N; i++ {
		if max <= list[i] {
			max = list[i]
			output++
		}
	}
	myout(output)
}

func main() {
	solve()
	flush()
}
// End of Code
