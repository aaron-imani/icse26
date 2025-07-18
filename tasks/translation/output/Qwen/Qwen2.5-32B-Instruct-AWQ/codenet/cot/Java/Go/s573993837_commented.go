package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Pair struct {
	u, v, i, val int
}

func solve(sc *InputReader, pw *bufio.Writer) {
	t := 1
	for t > 0 {
		n, _ := sc.nextLong()
		m, _ := sc.nextLong()
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

func fast_pow(base, n, M int) int {
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

func modInverse(n, M int) int {
	return fast_pow(n, M-2, M)
}

func feedArr(arr []int, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = sc.nextInt()
	}
}

func feedArr(arr []string, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i] = sc.next()
	}
}

func feedArr(arr []float64, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = sc.nextDouble()
	}
}

func feedArr(arr []int64, sc *InputReader) {
	for i := 0; i < len(arr); i++ {
		arr[i], _ = sc.nextLong()
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
	reader *bufio.Reader
}

func (sc *InputReader) next() string {
	line, _ := sc.reader.ReadString('\n')
	return line
}

func (sc *InputReader) nextInt() (int, error) {
	line, _ := sc.reader.ReadString('\n')
	return strconv.Atoi(line)
}

func (sc *InputReader) nextLong() (int64, error) {
	line, _ := sc.reader.ReadString('\n')
	return strconv.ParseInt(line, 10, 64)
}

func (sc *InputReader) nextDouble() (float64, error) {
	line, _ := sc.reader.ReadString('\n')
	return strconv.ParseFloat(line, 64)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := &InputReader{reader: bufio.NewReader(os.Stdin)}
	pw := bufio.NewWriter(os.Stdout)
	solve(sc, pw)
	pw.Flush()
}
// End of Code
