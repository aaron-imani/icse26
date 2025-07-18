package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var L, R, top, bottom int

func solve(sc *InputReader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n, _ := strconv.ParseInt(sc.next(), 10, 64)
		m, _ := strconv.ParseInt(sc.next(), 10, 64)
		if n == 0 {
			pw.WriteString("0\n")
			continue
		}
		if n == m {
			pw.WriteString("0\n")
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			pw.WriteString(fmt.Sprintf("%d\n", min(m-n, n)))
			continue
		}
		pw.WriteString(fmt.Sprintf("%d\n", min(m-n, n)))
	}
}

func swap(chrr []rune, i, j int) {
	temp := chrr[i]
	chrr[i] = chrr[j]
	chrr[j] = temp
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

func fast_pow(base, n, M int64) int64 {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return base
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

func feedArr(arr []int64, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.ParseInt(sc.next(), 10, 64)
	}
}

func feedArr(arr []float64, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.ParseFloat(sc.next(), 64)
	}
}

func feedArr(arr []int, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.Atoi(sc.next())
	}
}

func feedArr(arr []string, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = sc.next()
	}
}

func printArr(arr []int) string {
	sbr := ""
	for _, i := range arr {
		sbr += fmt.Sprintf("%d ", i)
	}
	return sbr
}

func printArr(arr []int64) string {
	sbr := ""
	for _, i := range arr {
		sbr += fmt.Sprintf("%d ", i)
	}
	return sbr
}

func printArr(arr []string) string {
	sbr := ""
	for _, i := range arr {
		sbr += fmt.Sprintf("%s ", i)
	}
	return sbr
}

func printArr(arr []float64) string {
	sbr := ""
	for _, i := range arr {
		sbr += fmt.Sprintf("%f ", i)
	}
	return sbr
}

type InputReader struct {
	reader     *bufio.Reader
	tokenizer  *bufio.Scanner
}

func (sc *InputReader) next() string {
	if !sc.tokenizer.Scan() {
		sc.tokenizer.Scan()
	}
	return sc.tokenizer.Text()
}

func (sc *InputReader) nextInt() int {
	return strconv.Atoi(sc.next())
}

func (sc *InputReader) nextLong() int64 {
	return strconv.ParseInt(sc.next(), 10, 64)
}

func (sc *InputReader) nextDouble() float64 {
	return strconv.ParseFloat(sc.next(), 64)
}

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	sc := &InputReader{bufio.NewReader(inputStream), bufio.NewScanner(inputStream)}
	pw := bufio.NewWriter(outputStream)
	solve(sc, pw)
	pw.Flush()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
// End of Code
