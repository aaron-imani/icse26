package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

type TokenReader struct {
	tokens []string
	pos    int
}

func (tr *TokenReader) nextInt() int {
	val, _ := strconv.Atoi(tr.tokens[tr.pos])
	tr.pos++
	return val
}

func (tr *TokenReader) nextLong() int64 {
	val, _ := strconv.ParseInt(tr.tokens[tr.pos], 10, 64)
	tr.pos++
	return val
}

func readAllTokens() []string {
	scanner := bufio.NewScanner(os.Stdin)
	var tokens []string
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		tokens = append(tokens, fields...)
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	return tokens
}

func lowerBound(a []int64, t int64) int {
	min, max := 0, len(a)
	for min < max {
		mid := (min + max) / 2
		if a[mid] >= t {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	tokens := readAllTokens()
	tr := &TokenReader{tokens: tokens, pos: 0}

	a := tr.nextInt()
	b := tr.nextInt()
	q := tr.nextInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = tr.nextLong()
	}
	s[a+1] = 20000000000

	tArr := make([]int64, b+2)
	tArr[0] = -10000000000
	for i := 0; i < b; i++ {
		tArr[i+1] = tr.nextLong()
	}
	tArr[b+1] = 20000000000

	for i := 0; i < q; i++ {
		x := tr.nextLong()

		xPlus1 := x + 1

		sUpperIdx := lowerBound(s, xPlus1)
		sPrevIdx := sUpperIdx - 1
		if sPrevIdx < 0 {
			sPrevIdx = 0
		}
		sl := x - s[sPrevIdx]

		tUpperIdx := lowerBound(tArr, xPlus1)
		tPrevIdx := tUpperIdx - 1
		if tPrevIdx < 0 {
			tPrevIdx = 0
		}
		tl := x - tArr[tPrevIdx]

		sUpperX := lowerBound(s, x)
		sr := s[sUpperX] - x

		tUpperX := lowerBound(tArr, x)
		trVal := tArr[tUpperX] - x

		aVal := max(sl, tl)
		bVal := max(sr, trVal)
		cVal := 2*sl + trVal
		dVal := 2*tl + sr
		eVal := sl + 2*trVal
		fVal := tl + 2*sr

		values := []int64{aVal, bVal, cVal, dVal, eVal, fVal}
		minVal := values[0]
		for _, v := range values[1:] {
			if v < minVal {
				minVal = v
			}
		}

		println(minVal)
	}
}
// End of Code
