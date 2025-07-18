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
	for t > 0 {
		t--
		n, _ := nextLong(in)
		m, _ := nextLong(in)
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

func feedArr(arr []int64, in *bufio.Reader) {
	for i := range arr {
		arr[i], _ = nextLong(in)
	}
}

func feedArrDouble(arr []float64, in *bufio.Reader) {
	for i := range arr {
		arr[i], _ = nextDouble(in)
	}
}

func feedArrInt(arr []int, in *bufio.Reader) {
	for i := range arr {
		arr[i], _ = nextInt(in)
	}
}

func feedArrString(arr []string, in *bufio.Reader) {
	for i := range arr {
		arr[i] = nextString(in)
	}
}

func printArr(arr []int) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%d ", i))
	}
	return sb.String()
}

func printArrLong(arr []int64) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%d ", i))
	}
	return sb.String()
}

func printArrString(arr []string) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%s ", i))
	}
	return sb.String()
}

func printArrDouble(arr []float64) string {
	var sb strings.Builder
	for _, i := range arr {
		sb.WriteString(fmt.Sprintf("%f ", i))
	}
	return sb.String()
}

func nextString(in *bufio.Reader) string {
	line, _ := in.ReadString('\n')
	return strings.TrimSpace(line)
}

func nextInt(in *bufio.Reader) (int, error) {
	line, _ := in.ReadString('\n')
	n, err := strconv.Atoi(strings.TrimSpace(line))
	return n, err
}

func nextLong(in *bufio.Reader) (int64, error) {
	line, _ := in.ReadString('\n')
	n, err := strconv.ParseInt(strings.TrimSpace(line), 10, 64)
	return n, err
}

func nextDouble(in *bufio.Reader) (float64, error) {
	line, _ := in.ReadString('\n')
	n, err := strconv.ParseFloat(strings.TrimSpace(line), 64)
	return n, err
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
