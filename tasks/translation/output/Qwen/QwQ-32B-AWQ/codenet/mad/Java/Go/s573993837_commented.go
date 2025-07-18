package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var L, R, top, bottom int

type Pair struct {
	u, v, i, val int
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func swap(chrr []rune, i, j int) {
	temp := chrr[i]
	chrr[i] = chrr[j]
	chrr[j] = temp
}

func num(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
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
	i := 5
	for i*i <= n {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
		i += 6
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

func fast_pow(base, n, M int64) int64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return base % M
	}
	halfn := fast_pow(base, n/2, M)
	if n%2 == 0 {
		return (halfn * halfn) % M
	}
	return ((halfn * halfn) % M * base) % M
}

func modInverse(n, M int64) int64 {
	return fast_pow(n, M-2, M)
}

func feedArrLong(arr []int64, in *InputReader) {
	for i := range arr {
		arr[i] = in.nextLong()
	}
}

func feedArrDouble(arr []float64, in *InputReader) {
	for i := range arr {
		arr[i] = in.nextDouble()
	}
}

func feedArrInt(arr []int, in *InputReader) {
	for i := range arr {
		arr[i] = in.nextInt()
	}
}

func feedArrString(arr []string, in *InputReader) {
	for i := range arr {
		arr[i] = in.next()
	}
}

func printArrInt(arr []int) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(strconv.Itoa(i))
		sb.WriteString(" ")
	}
	return sb.String()
}

func printArrLong(arr []int64) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(strconv.FormatInt(i, 10))
		sb.WriteString(" ")
	}
	return sb.String()
}

func printArrString(arr []string) string {
	var sb strings.Builder
	for _, s := range arr {
		sb.WriteString(s)
		sb.WriteString(" ")
	}
	return sb.String()
}

func printArrDouble(arr []float64) string {
	var sb strings.Builder
	for _, d := range arr {
		sb.WriteString(strconv.FormatFloat(d, 'f', -1, 64))
		sb.WriteString(" ")
	}
	return sb.String()
}

type InputReader struct {
	scanner *bufio.Scanner
	tokens  []string
	index   int
}

func NewInputReader(r *bufio.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{
		scanner: scanner,
		tokens:  make([]string, 0),
		index:   0,
	}
}

func (r *InputReader) next() string {
	if r.index < len(r.tokens) {
		s := r.tokens[r.index]
		r.index++
		return s
	}
	if !r.scanner.Scan() {
		panic("No more tokens")
	}
	token := r.scanner.Text()
	r.tokens = append(r.tokens, token)
	r.index++
	return token
}

func (r *InputReader) nextInt() int {
	n, _ := strconv.Atoi(r.next())
	return n
}

func (r *InputReader) nextLong() int64 {
	n, _ := strconv.ParseInt(r.next(), 10, 64)
	return n
}

func (r *InputReader) nextDouble() float64 {
	n, _ := strconv.ParseFloat(r.next(), 64)
	return n
}

func solve(in *InputReader, out *bufio.Writer) {
	t := 1
	for ; t > 0; t-- {
		n := in.nextLong()
		m := in.nextLong()
		if n == 0 {
			fmt.Fprintln(out, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(out, 0)
			continue
		}
		if n > m {
			n %= m
		}
		fmt.Fprintln(out, min(m-n, n))
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)
	in := NewInputReader(r)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}

// End of Code
