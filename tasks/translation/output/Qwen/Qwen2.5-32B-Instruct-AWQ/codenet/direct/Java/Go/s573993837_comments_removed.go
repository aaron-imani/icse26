package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

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

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	if a > b {
		return gcd(b, a%b)
	}
	return gcd(a, b%a)
}

func fastPow(base, n, M int) int {
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
	return ((halfn * halfn) % M * base) % M
}

func modInverse(n, M int) int {
	return fastPow(n, M-2, M)
}

func feedArr(arr []int, sc *bufio.Reader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = nextInt(sc)
	}
}

func feedArr(arr []string, sc *bufio.Reader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = next(sc)
	}
}

func feedArr(arr []float64, sc *bufio.Reader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = nextDouble(sc)
	}
}

func feedArr(arr []int64, sc *bufio.Reader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = nextInt64(sc)
	}
}

func printArr(arr []int) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%d ", i))
	}
	return sbr.String()
}

func printArr(arr []int64) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%d ", i))
	}
	return sbr.String()
}

func printArr(arr []string) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%s ", i))
	}
	return sbr.String()
}

func printArr(arr []float64) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%f ", i))
	}
	return sbr.String()
}

func next(sc *bufio.Reader) string {
	line, _ := sc.ReadString('\n')
	return strings.TrimSpace(line)
}

func nextInt(sc *bufio.Reader) int {
	line := next(sc)
	n, _ := strconv.Atoi(line)
	return n
}

func nextInt64(sc *bufio.Reader) int64 {
	line := next(sc)
	n, _ := strconv.ParseInt(line, 10, 64)
	return n
}

func nextDouble(sc *bufio.Reader) float64 {
	line := next(sc)
	n, _ := strconv.ParseFloat(line, 64)
	return n
}

func solve(sc *bufio.Reader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n := nextInt64(sc)
		m := nextInt64(sc)
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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewReader(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	solve(sc, pw)
	pw.Flush()
}
// End of Code
