package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	tokens []string
	pos    int
}

func readAllTokens() ([]string, error) {
	scanner := bufio.NewScanner(os.Stdin)
	var tokens []string
	for scanner.Scan() {
		fields := strings.Fields(scanner.Text())
		tokens = append(tokens, fields...)
	}
	if err := scanner.Err(); err != nil {
		return nil, err
	}
	return tokens, nil
}

func NewLightScanner() *LightScanner {
	tokens, _ := readAllTokens()
	return &LightScanner{tokens: tokens, pos: 0}
}

func (s *LightScanner) Next() string {
	if s.pos >= len(s.tokens) {
		panic("no more tokens")
	}
	s.pos++
	return s.tokens[s.pos-1]
}

func (s *LightScanner) NextInt() int {
	n, _ := strconv.Atoi(s.Next())
	return n
}

func (s *LightScanner) NextLong() int64 {
	n, _ := strconv.ParseInt(s.Next(), 10, 64)
	return n
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter() *LightWriter {
	return &LightWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (w *LightWriter) Println(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
}

func (w *LightWriter) Flush() {
	w.writer.Flush()
}

func lowerBound(arr []int64, t int64) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < t {
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

func min(arr []int64) int64 {
	m := arr[0]
	for _, v := range arr {
		if v < m {
			m = v
		}
	}
	return m
}

func main() {
	scanner := NewLightScanner()
	writer := NewLightWriter()

	a := scanner.NextInt()
	b := scanner.NextInt()
	q := scanner.NextInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = scanner.NextLong()
	}
	s[a+1] = 20000000000

	t := make([]int64, b+2)
	t[0] = -10000000000
	for i := 0; i < b; i++ {
		t[i+1] = scanner.NextLong()
	}
	t[b+1] = 20000000000

	for i := 0; i < q; i++ {
		x := scanner.NextLong()

		idxS := lowerBound(s, x+1)
		prevS := idxS - 1
		if prevS < 0 {
			prevS = 0
		}
		sl := x - s[prevS]

		idxT := lowerBound(t, x+1)
		prevT := idxT - 1
		if prevT < 0 {
			prevT = 0
		}
		tl := x - t[prevT]

		idxSR := lowerBound(s, x)
		sr := s[idxSR] - x

		idxTR := lowerBound(t, x)
		tr := t[idxTR] - x

		terms := []int64{
			max(sl, tl),
			max(sr, tr),
			2*sl + tr,
			2*tl + sr,
			sl + 2*tr,
			tl + 2*sr,
		}

		minVal := min(terms)
		writer.Println(minVal)
	}

	writer.Flush()
}

// End of Code
