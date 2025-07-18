package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func lowerBound(a []int64, t int64) int {
	left, right := 0, len(a)
	for left < right {
		mid := (left + right) / 2
		if a[mid] < t {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

type scanner struct {
	tokens []string
	idx    int
}

func newScanner(r io.Reader) *scanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	var tokens []string
	for sc.Scan() {
		tokens = append(tokens, sc.Text())
	}
	return &scanner{tokens: tokens, idx: 0}
}

func (s *scanner) nextInt() int {
	n, _ := strconv.Atoi(s.tokens[s.idx])
	s.idx++
	return n
}

func (s *scanner) nextLong() int64 {
	n, _ := strconv.ParseInt(s.tokens[s.idx], 10, 64)
	s.idx++
	return n
}

func main() {
	sc := newScanner(os.Stdin)
	a := sc.nextInt()
	b := sc.nextInt()
	q := sc.nextInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = sc.nextLong()
	}
	s[a+1] = 20000000000

	t := make([]int64, b+2)
	t[0] = -10000000000
	for i := 0; i < b; i++ {
		t[i+1] = sc.nextLong()
	}
	t[b+1] = 20000000000

	for i := 0; i < q; i++ {
		x := sc.nextLong()

		idx_s_l := lowerBound(s, x+1)
		prevIndexS := idx_s_l - 1
		if prevIndexS < 0 {
			prevIndexS = 0
		}
		sl := x - s[prevIndexS]

		idx_t_l := lowerBound(t, x+1)
		prevIndexT := idx_t_l - 1
		if prevIndexT < 0 {
			prevIndexT = 0
		}
		tl := x - t[prevIndexT]

		srIndex := lowerBound(s, x)
		sr := s[srIndex] - x

		trIndex := lowerBound(t, x)
		tr := t[trIndex] - x

		term1 := max(sl, tl)
		term2 := max(sr, tr)
		term3 := 2*sl + tr
		term4 := 2*tl + sr
		term5 := sl + 2*tr
		term6 := tl + 2*sr

		minVal := term1
		if term2 < minVal {
			minVal = term2
		}
		if term3 < minVal {
			minVal = term3
		}
		if term4 < minVal {
			minVal = term4
		}
		if term5 < minVal {
			minVal = term5
		}
		if term6 < minVal {
			minVal = term6
		}

		fmt.Println(minVal)
	}
}

// End of Code
