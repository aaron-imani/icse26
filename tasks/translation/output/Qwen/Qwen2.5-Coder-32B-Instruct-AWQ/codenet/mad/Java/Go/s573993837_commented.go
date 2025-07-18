package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var L, R, top, bottom int

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve(in, out)
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	t := 1
	for ; t > 0; t-- {
		line, _ := in.ReadString('\n')
		parts := strings.Fields(line)
		n, _ := strconv.ParseInt(parts[0], 10, 64)
		m, _ := strconv.ParseInt(parts[1], 10, 64)
		if n == 0 {
			fmt.Fprintln(out, 0)
			continue
		}
		if n == m {
			fmt.Fprintln(out, 0)
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Fprintln(out, min(m-n, n))
			continue
		}
		fmt.Fprintln(out, min(m-n, n))
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
	return gcd(b, a%b)
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

func feedArr(arr []int64, in *bufio.Reader) {
	line, _ := in.ReadString('\n')
	parts := strings.Fields(line)
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.ParseInt(parts[i], 10, 64)
	}
}

func feedArrDouble(arr []float64, in *bufio.Reader) {
	line, _ := in.ReadString('\n')
	parts := strings.Fields(line)
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.ParseFloat(parts[i], 64)
	}
}

func feedArrInt(arr []int, in *bufio.Reader) {
	line, _ := in.ReadString('\n')
	parts := strings.Fields(line)
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.Atoi(parts[i])
	}
}

func feedArrString(arr []string, in *bufio.Reader) {
	line, _ := in.ReadString('\n')
	parts := strings.Fields(line)
	for i := 0; i < len(arr); i++ {
		arr[i] = parts[i]
	}
}

func printArrInt(arr []int) string {
	var result strings.Builder
	for _, i := range arr {
		result.WriteString(fmt.Sprintf("%d ", i))
	}
	return result.String()
}

func printArrLong(arr []int64) string {
	var result strings.Builder
	for _, i := range arr {
		result.WriteString(fmt.Sprintf("%d ", i))
	}
	return result.String()
}

func printArrString(arr []string) string {
	var result strings.Builder
	for _, i := range arr {
		result.WriteString(fmt.Sprintf("%s ", i))
	}
	return result.String()
}

func printArrDouble(arr []float64) string {
	var result strings.Builder
	for _, i := range arr {
		result.WriteString(fmt.Sprintf("%f ", i))
	}
	return result.String()
}

// End of Code
