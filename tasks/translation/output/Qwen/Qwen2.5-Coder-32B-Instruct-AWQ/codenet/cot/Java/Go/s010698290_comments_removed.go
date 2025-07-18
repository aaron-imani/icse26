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

func (fr *FastReader) Next() string {
	for fr.r.Buffered() == 0 {
		_, err := fr.r.ReadBytes('\n')
		if err != nil {
			panic(err)
		}
	}
	str, _ := fr.r.ReadString('\n')
	return strings.TrimSpace(str)
}

func (fr *FastReader) NextInt() int {
	str := fr.Next()
	num, _ := strconv.Atoi(str)
	return num
}

func main() {
	fr := NewFastReader()
	n := fr.NextInt()
	m := fr.NextInt()

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		num := fr.NextInt()
		str := fr.Next()
		if str == "A" {
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
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
