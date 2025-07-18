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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}

func solve(reader *bufio.Reader, writer *bufio.Writer) {
	t := 1
	for t > 0 {
		line, _ := reader.ReadString('\n')
		inputs := strings.Fields(line)
		n, _ := strconv.ParseInt(inputs[0], 10, 64)
		m, _ := strconv.ParseInt(inputs[1], 10, 64)

		if n == 0 {
			fmt.Fprintln(writer, 0)
			t--
			continue
		}
		if n == m {
			fmt.Fprintln(writer, 0)
			t--
			continue
		}
		if n > m {
			n = m + n%m
			n -= m
			fmt.Fprintln(writer, min(m-n, n))
			t--
			continue
		}
		fmt.Fprintln(writer, min(m-n, n))
		t--
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
	halfN := fastPow(base, n/2, M)
	if n%2 == 0 {
		return (halfN * halfN) % M
	}
	return (((halfN * halfN) % M) * base) % M
}

func modInverse(n, M int64) int64 {
	return fastPow(n, M-2, M)
}

// End of Code
