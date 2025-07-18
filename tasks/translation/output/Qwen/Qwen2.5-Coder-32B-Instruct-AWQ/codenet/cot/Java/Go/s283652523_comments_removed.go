package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	in := NewFastScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve(in, out)
}

func solve(in *FastScanner, out *bufio.Writer) {
	N := in.NextInt()
	A := in.NextIntArray(N)

	ans, sum := 0, A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans = (ans + (sum*A[i])%MOD) % MOD
		sum = (sum + A[i]) % MOD
	}
	fmt.Fprintln(out, ans)
}

type FastScanner struct {
	reader *bufio.Reader
}

func NewFastScanner(r *os.File) *FastScanner {
	return &FastScanner{bufio.NewReader(r)}
}

func (s *FastScanner) Next() string {
	var buf strings.Builder
	for {
		b, err := s.reader.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == '\n' || b == ' ' {
			break
		}
		buf.WriteByte(b)
	}
	return buf.String()
}

func (s *FastScanner) NextInt() int {
	i, err := strconv.Atoi(s.Next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *FastScanner) NextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = s.NextInt()
	}
	return a
}

// End of Code
