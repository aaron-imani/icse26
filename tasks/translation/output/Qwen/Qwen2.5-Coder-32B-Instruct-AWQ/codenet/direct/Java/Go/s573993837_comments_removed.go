package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	L, R, top, bottom int
)

func main() {
	inputReader := bufio.NewReader(os.Stdin)
	outputWriter := bufio.NewWriter(os.Stdout)
	defer outputWriter.Flush()
	sc := NewScanner(inputReader)
	solve(sc, outputWriter)
}

func solve(sc *Scanner, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		t--
		n := sc.NextInt64()
		m := sc.NextInt64()
		if n == 0 {
			fmt.Fprintln(pw, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(pw, 0)
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Fprintln(pw, min(m-n, n))
			continue
		}
		fmt.Fprintln(pw, min(m-n, n))
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func swap(chrr []rune, i, j int) {
	chrr[i], chrr[j] = chrr[j], chrr[i]
}

func num(n int) int {
	a := 0
	for n > 0 {
		a += n & 1
		n >>= 1
	}
	return a
}

type Pair struct {
	u, v, i, val int
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	if a > b {
		return gcd(b, a%b)
	}
	return gcd(a, b%a)
}

func fastPow(base, n, M int64) int64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return base
	}
	halfn := fastPow(base, n/2, M)
	if n%2 == 0 {
		return (halfn * halfn) % M
	}
	return (((halfn * halfn) % M) * base) % M
}

func modInverse(n, M int64) int64 {
	return fastPow(n, M-2, M)
}

func feedArr(arr []int64, sc *Scanner) {
	for i := range arr {
		arr[i] = sc.NextInt64()
	}
}

func feedArrStr(arr []string, sc *Scanner) {
	for i := range arr {
		arr[i] = sc.Next()
	}
}

func printArr(arr []int) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%d ", i))
	}
	return sb.String()
}

func printArrInt64(arr []int64) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%d ", i))
	}
	return sb.String()
}

func printArrStr(arr []string) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%s ", i))
	}
	return sb.String()
}

type Scanner struct {
	r *bufio.Reader
}

func NewScanner(r *bufio.Reader) *Scanner {
	return &Scanner{r}
}

func (s *Scanner) Next() string {
	var buf []byte
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == ' ' || b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

func (s *Scanner) NextInt64() int64 {
	i, err := strconv.ParseInt(s.Next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (s *Scanner) NextInt() int {
	return int(s.NextInt64())
}

func (s *Scanner) NextFloat64() float64 {
	f, err := strconv.ParseFloat(s.Next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

func (s *Scanner) NextLine() string {
	var buf []byte
	for {
		b, err := s.r.ReadByte()
		if err != nil {
			panic(err)
		}
		if b == '\n' {
			break
		}
		buf = append(buf, b)
	}
	return string(buf)
}

// End of Code
