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
	r *bufio.Reader
}

func NewFastScanner(r *os.File) *FastScanner {
	return &FastScanner{bufio.NewReader(r)}
}

func (s *FastScanner) Next() string {
	var buf strings.Builder
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			fmt.Println(err)
			return ""
		}
		if b <= 32 {
			break
		}
		buf.WriteByte(b)
	}
	return buf.String()
}

func (s *FastScanner) NextInt() int {
	str := s.Next()
	num, err := strconv.Atoi(str)
	if err != nil {
		fmt.Println(err)
		return 0
	}
	return num
}

func (s *FastScanner) NextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = s.NextInt()
	}
	return a
}
// End of Code
