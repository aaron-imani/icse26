package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	r *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) next() string {
	str, _, _ := fr.r.ReadLine()
	return strings.TrimSpace(string(str))
}

func (fr *FastReader) nextInt() int {
	str := fr.next()
	num, _ := strconv.Atoi(str)
	return num
}

func main() {
	fr := NewFastReader()
	n := fr.nextInt()
	m := fr.nextInt()

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		num := fr.nextInt()
		str := fr.next()
		if str[0] == 'A' {
			solved[num] = true
		} else if !solved[num] {
			penal[num]++
		}
	}

	correctAns := 0
	numPenal := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correctAns++
			numPenal += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correctAns, numPenal)
}

// End of Code
