package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Scanner struct {
	tokens []string
	idx    int
}

func NewScanner(r *bufio.Reader) *Scanner {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	tokens := []string{}
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	return &Scanner{tokens: tokens, idx: 0}
}

func (sc *Scanner) Next() string {
	if sc.idx >= len(sc.tokens) {
		panic("no more tokens")
	}
	token := sc.tokens[sc.idx]
	sc.idx++
	return token
}

func (sc *Scanner) NextInt() int {
	n, err := strconv.Atoi(sc.Next())
	if err != nil {
		panic(err)
	}
	return n
}

func (sc *Scanner) NextLong() int64 {
	n, err := strconv.ParseInt(sc.Next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return n
}

func lowerBound(a []int64, target int64) int {
	return sort.Search(len(a), func(i int) bool { return a[i] >= target })
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	sc := NewScanner(reader)

	a := sc.NextInt()
	b := sc.NextInt()
	q := sc.NextInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	s[a+1] = 20000000000
	for i := 1; i <= a; i++ {
		s[i] = sc.NextLong()
	}

	t := make([]int64, b+2)
	t[0] = -10000000000
	t[b+1] = 20000000000
	for i := 1; i <= b; i++ {
		t[i] = sc.NextLong()
	}

	for query := 0; query < q; query++ {
		x := sc.NextLong()

		sPlus := lowerBound(s, x+1)
		var sPrevIndex int
		sPrevIndex = sPlus - 1
		if sPrevIndex < 0 {
			sPrevIndex = 0
		}
		sl := x - s[sPrevIndex]

		tPlus := lowerBound(t, x+1)
		var tPrevIndex int
		tPrevIndex = tPlus - 1
		if tPrevIndex < 0 {
			tPrevIndex = 0
		}
		tl := x - t[tPrevIndex]

		sIdx := lowerBound(s, x)
		sr := s[sIdx] - x

		tIdx := lowerBound(t, x)
		tr := t[tIdx] - x

		c1 := max(sl, tl)
		c2 := max(sr, tr)
		c3 := 2*sl + tr
		c4 := 2*tl + sr
		c5 := sl + 2*tr
		c6 := tl + 2*sr

		minVal := c1
		if c2 < minVal {
			minVal = c2
		}
		if c3 < minVal {
			minVal = c3
		}
		if c4 < minVal {
			minVal = c4
		}
		if c5 < minVal {
			minVal = c5
		}
		if c6 < minVal {
			minVal = c6
		}

		fmt.Fprintln(writer, minVal)
	}
}

// End of Code
