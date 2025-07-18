package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var CONVSTR = map[int]string{8: " ", 9: "\n", 0: ""}
var ii *InputIterator
var out = bufio.NewWriter(os.Stdout)

type InputIterator struct {
	inputLine []string
	index     int
	max       int
	read      string
}

func NewInputIterator() *InputIterator {
	br := bufio.NewReader(os.Stdin)
	inputLine := make([]string, 0)
	for {
		read, err := br.ReadString('\n')
		if err != nil {
			break
		}
		inputLine = append(inputLine, strings.TrimSpace(read))
	}
	return &InputIterator{inputLine: inputLine, max: len(inputLine)}
}

func (ii *InputIterator) hasNext() bool {
	return ii.index < ii.max
}

func (ii *InputIterator) next() string {
	if ii.hasNext() {
		val := ii.inputLine[ii.index]
		ii.index++
		return val
	} else {
		panic("There is no more input")
	}
}

func flush() {
	out.Flush()
}

func myout(t interface{}) {
	fmt.Fprintln(out, t)
}

func myerr(t interface{}) {
	fmt.Fprintf(os.Stderr, "debug: %v\n", t)
}

func next() string {
	return ii.next()
}

func hasNext() bool {
	return ii.hasNext()
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
	return myconv(next(), 8)
}

func nextCharArray() []string {
	return myconv(next(), 0)
}

func nextIntArray() []int {
	input := nextStrArray()
	ret := make([]int, len(input))
	for i, str := range input {
		ret[i], _ = strconv.Atoi(str)
	}
	return ret
}

func nextLongArray() []int64 {
	input := nextStrArray()
	ret := make([]int64, len(input))
	for i, str := range input {
		ret[i], _ = strconv.ParseInt(str, 10, 64)
	}
	return ret
}

func myconv(list interface{}, no int) string {
	joinString := CONVSTR[no]
	switch l := list.(type) {
	case []string:
		return strings.Join(l, joinString)
	case []interface{}:
		strs := make([]string, len(l))
		for i, v := range l {
			strs[i] = fmt.Sprintf("%v", v)
		}
		return strings.Join(strs, joinString)
	default:
		panic("Don't join")
	}
}

func myconv(str string, no int) []string {
	splitString := CONVSTR[no]
	return strings.Split(str, splitString)
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

func main() {
	ii = NewInputIterator()
	solve()
	flush()
}
// End of Code
