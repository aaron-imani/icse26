package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sort"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

type Scanner struct {
	tokens []string
	pos    int
}

func NewScanner() *Scanner {
	data, err := io.ReadAll(os.Stdin)
	if err != nil {
		panic(err)
	}
	s := string(data)
	return &Scanner{
		tokens: strings.Fields(s),
		pos:    0,
	}
}

func (s *Scanner) next() string {
	if s.pos >= len(s.tokens) {
		panic("no more tokens")
	}
	token := s.tokens[s.pos]
	s.pos++
	return token
}

func (s *Scanner) nextInt() int {
	n, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return n
}

func (s *Scanner) nextInt64() int64 {
	n, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return n
}

type LightWriter struct {
	writer *bufio.Writer
}

func NewLightWriter() *LightWriter {
	return &LightWriter{
		writer: bufio.NewWriter(os.Stdout),
	}
}

func (lw *LightWriter) Println(value int64) {
	s := strconv.FormatInt(value, 10)
	lw.writer.WriteString(s)
	lw.writer.WriteString("\n")
}

func (lw *LightWriter) Flush() {
	lw.writer.Flush()
}

func main() {
	scanner := NewScanner()
	lw := NewLightWriter()

	a := scanner.nextInt()
	b := scanner.nextInt()
	q := scanner.nextInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = scanner.nextInt64()
	}
	s[a+1] = 20000000000

	t := make([]int64, b+2)
	t[0] = -10000000000
	for i := 0; i < b; i++ {
		t[i+1] = scanner.nextInt64()
	}
	t[b+1] = 20000000000

	for i := 0; i < q; i++ {
		x := scanner.nextInt64()

		slIndex := sort.Search(len(s), func(i int) bool { return s[i] >= x+1 }) - 1
		if slIndex < 0 {
			slIndex = 0
		}
		sl := x - s[slIndex]

		tlIndex := sort.Search(len(t), func(i int) bool { return t[i] >= x+1 }) - 1
		if tlIndex < 0 {
			tlIndex = 0
		}
		tl := x - t[tlIndex]

		srIndex := sort.Search(len(s), func(i int) bool { return s[i] >= x })
		sr := s[srIndex] - x

		trIndex := sort.Search(len(t), func(i int) bool { return t[i] >= x })
		tr := t[trIndex] - x

		candidates := []int64{
			max(sl, tl),
			max(sr, tr),
			2*sl + tr,
			2*tl + sr,
			sl + 2*tr,
			tl + 2*sr,
		}
		minVal := candidates[0]
		for _, val := range candidates[1:] {
			if val < minVal {
				minVal = val
			}
		}
		lw.Println(minVal)
	}
	lw.Flush()
}

// End of Code
