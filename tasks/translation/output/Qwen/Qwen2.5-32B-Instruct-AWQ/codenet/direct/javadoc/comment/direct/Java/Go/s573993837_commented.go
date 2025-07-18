package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Pair struct {
	u   int
	v   int
	i   int
	val int
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
	halfN := fastPow(base, n/2, M)
	if n%2 == 0 {
		return (halfN * halfN) % M
	}
	return (((halfN * halfN) % M) * base) % M
}

func modInverse(n, M int) int {
	return fastPow(n, M-2, M)
}

func feedArr(arr []int, sc *bufio.Reader) {
	for i := range arr {
		arr[i], _ = strconv.Atoi(readLine(sc))
	}
}

func feedArrStr(arr []string, sc *bufio.Reader) {
	for i := range arr {
		arr[i] = readLine(sc)
	}
}

func feedArrFloat(arr []float64, sc *bufio.Reader) {
	for i := range arr {
		arr[i], _ = strconv.ParseFloat(readLine(sc), 64)
	}
}

func feedArrLong(arr []int64, sc *bufio.Reader) {
	for i := range arr {
		arr[i], _ = strconv.ParseInt(readLine(sc), 10, 64)
	}
}

func printArr(arr []int) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%d ", i))
	}
	return sbr.String()
}

func printArrLong(arr []int64) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%d ", i))
	}
	return sbr.String()
}

func printArrStr(arr []string) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%s ", i))
	}
	return sbr.String()
}

func printArrFloat(arr []float64) string {
	var sbr strings.Builder
	for _, i := range arr {
		sbr.WriteString(fmt.Sprintf("%f ", i))
	}
	return sbr.String()
}

func readLine(sc *bufio.Reader) string {
	line, _ := sc.ReadString('\n')
	return strings.TrimSpace(line)
}

func solve(sc *bufio.Reader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n, _ := strconv.ParseInt(readLine(sc), 10, 64)
		m, _ := strconv.ParseInt(readLine(sc), 10, 64)
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
		t--
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	solve(scanner, writer)
} // End of Code
