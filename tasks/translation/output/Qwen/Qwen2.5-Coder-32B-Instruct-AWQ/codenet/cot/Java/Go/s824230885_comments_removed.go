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

func (ii *InputIterator) hasNext() bool {
	return ii.index < ii.max
}

func (ii *InputIterator) next() string {
	if ii.hasNext() {
		result := ii.inputLine[ii.index]
		ii.index++
		return result
	}
	panic("There is no more input")
}

var CONVSTR = map[int]string{}
var ii = NewInputIterator()
var out = bufio.NewWriter(os.Stdout)

func flush() {
	out.Flush()
}

func myout(t interface{}) {
	fmt.Fprintln(out, t)
}

func myerr(t interface{}) {
	fmt.Fprintln(os.Stderr, "debug:", t)
}

func next() string {
	return ii.next()
}

func hasNext() bool {
	return ii.hasNext()
}

func nextInt() int {
	s := next()
	i, _ := strconv.Atoi(s)
	return i
}

func nextLong() int64 {
	s := next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func nextDouble() float64 {
	s := next()
	f, _ := strconv.ParseFloat(s, 64)
	return f
}

func nextStrArray() []string {
	return myconv(next(), 8)
}

func nextCharArray() []string {
	return myconv(next(), 0)
}

func nextIntArray() []int {
	input := nextStrArray()
	ret := make([]int, len(input))
	for i, s := range input {
		ret[i], _ = strconv.Atoi(s)
	}
	return ret
}

func nextLongArray() []int64 {
	input := nextStrArray()
	ret := make([]int64, len(input))
	for i, s := range input {
		ret[i], _ = strconv.ParseInt(s, 10, 64)
	}
	return ret
}

func myconv(list interface{}, no int) string {
	joinString := CONVSTR[no]
	switch v := list.(type) {
	case []string:
		return strings.Join(v, joinString)
	case []interface{}:
		strs := make([]string, len(v))
		for i, item := range v {
			strs[i] = item.(string)
		}
		return strings.Join(strs, joinString)
	default:
		panic("Don't join")
	}
}

func myconvStr(str string, no int) []string {
	splitString := CONVSTR[no]
	return strings.Split(str, splitString)
}

func main() {
	CONVSTR[8] = " "
	CONVSTR[9] = "\n"
	CONVSTR[0] = ""
	solve()
	flush()
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
	myout(output)
}
// End of Code
