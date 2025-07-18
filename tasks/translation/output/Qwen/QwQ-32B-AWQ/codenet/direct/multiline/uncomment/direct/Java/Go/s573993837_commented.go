package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type InputReader struct {
	tokens []string
	idx    int
}

func NewInputReader(r *bufio.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	return &InputReader{tokens, 0}
}

func (r *InputReader) Next() string {
	if r.idx < len(r.tokens) {
		r.idx++
		return r.tokens[r.idx-1]
	}
	return ""
}

func (r *InputReader) NextInt() int {
	num, _ := strconv.Atoi(r.Next())
	return num
}

func (r *InputReader) NextInt64() int64 {
	num, _ := strconv.ParseInt(r.Next(), 10, 64)
	return num
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solve(sc *InputReader, out *bufio.Writer) {
	t := sc.NextInt()
	for t > 0 {
		n := sc.NextInt64()
		m := sc.NextInt64()
		if n == 0 {
			fmt.Fprintln(out, 0)
			t--
			continue
		}
		if n == m {
			fmt.Fprintln(out, 0)
			t--
			continue
		}
		if n > m {
			rem := n % m
			res := min(rem, m-rem)
			fmt.Fprintln(out, res)
		} else {
			res := min(n, m-n)
			fmt.Fprintln(out, res)
		}
		t--
	}
	out.Flush()
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	sc := NewInputReader(reader)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	solve(sc, writer)
}

// End of Code
