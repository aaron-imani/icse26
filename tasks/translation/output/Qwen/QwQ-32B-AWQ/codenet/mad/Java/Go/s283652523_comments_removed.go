package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

const MOD int64 = 1000000007

type FastScanner struct {
	tokens []string
	idx    int
}

func NewFastScanner(r io.Reader) *FastScanner {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	var tokens []string
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	return &FastScanner{tokens: tokens, idx: 0}
}

func (fs *FastScanner) NextInt() int {
	n, _ := strconv.Atoi(fs.tokens[fs.idx])
	fs.idx++
	return n
}

func (fs *FastScanner) NextIntArray(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = fs.NextInt()
	}
	return a
}

func main() {
	fs := NewFastScanner(os.Stdin)
	N := fs.NextInt()
	A := fs.NextIntArray(N)
	var ans int64
	var sum int64 = int64(A[N-1])
	ans = 0
	for i := N - 2; i >= 0; i-- {
		term := (sum * int64(A[i])) % MOD
		ans = (ans + term) % MOD
		sum = (sum + int64(A[i])) % MOD
	}
	fmt.Println(ans % MOD)
}

// End of Code
