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

	ans, sum := int64(0), int64(A[N-1])
	for i := N - 2; i >= 0; i-- {
		ans += (sum * int64(A[i])) % MOD
		ans %= MOD
		sum += int64(A[i])
		sum %= MOD
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
	i, _ := strconv.Atoi(s.Next())
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
