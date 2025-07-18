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
	var inputLine []string
	for {
		line, _, err := reader.ReadLine()
		if err != nil {
			break
		}
		inputLine = append(inputLine, string(line))
	}
	return &InputIterator{inputLine: inputLine, max: len(inputLine)}
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

var CONVSTR = map[int]string{
	8: " ",
	9: "\n",
	0: "",
}

var ii = NewInputIterator()

func next() string {
	return ii.Next()
}

func hasNext() bool {
	return ii.HasNext()
}

func nextInt() int {
	num, _ := strconv.Atoi(next())
	return num
}

func nextLong() int64 {
	num, _ := strconv.ParseInt(next(), 10, 64)
	return num
}

func nextDouble() float64 {
	num, _ := strconv.ParseFloat(next(), 64)
	return num
}

func nextStrArray() []string {
	return strings.Fields(next())
}

func nextCharArray() []string {
	return strings.Split(next(), "")
}

func nextIntArray() []int {
	strArray := nextStrArray()
	intArray := make([]int, len(strArray))
	for i, str := range strArray {
		intArray[i], _ = strconv.Atoi(str)
	}
	return intArray
}

func nextLongArray() []int64 {
	strArray := nextStrArray()
	longArray := make([]int64, len(strArray))
	for i, str := range strArray {
		longArray[i], _ = strconv.ParseInt(str, 10, 64)
	}
	return longArray
}

func myconv(list interface{}, no int) string {
	joinString := CONVSTR[no]
	switch v := list.(type) {
	case []string:
		return strings.Join(v, joinString)
	case []interface{}:
		strArray := make([]string, len(v))
		for i, item := range v {
			strArray[i] = fmt.Sprintf("%v", item)
		}
		return strings.Join(strArray, joinString)
	default:
		panic("Don't join")
	}
}

func myconvString(str string, no int) []string {
	splitString := CONVSTR[no]
	return strings.Split(str, splitString)
}

func main() {
	solve()
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

// End of Code
