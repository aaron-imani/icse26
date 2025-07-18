package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

var to [][]int
var dp []int

func main() {
	sc := NewScanner(os.Stdin)
	N := sc.nextInt()
	to = make([][]int, N)
	for i := 0; i < N; i++ {
		to[i] = []int{}
	}
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A := sc.nextInt() - 1
		B := sc.nextInt() - 1
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i][0] = B
		edges[i][1] = A
	}
	dp = make([]int, N)
	rec(0, -1)
	mulsum := 0
	for _, e := range edges {
		candidate1 := e[0]
		candidate2 := e[1]
		child := candidate1
		if dp[candidate1] > dp[candidate2] {
			child = candidate2
		}
		a := int64(dp[child])
		b := int64(N - dp[child])
		mul := (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod
		mulsum = (mulsum + mul) % mod
	}
	cases := modpow(2, int64(N))
	PN := (mulsum + (cases - 1 + int64(mod)) % int64(mod)) % int64(mod)
	BN := int64(N) * modpow(2, int64(N-1)) % int64(mod)
	WN := (PN - BN + int64(mod)) % int64(mod)
	ans := WN * modpow(cases, int64(mod-2)) % int64(mod)
	fmt.Println(ans)
}

func rec(v, parent int) int {
	res := 1
	for _, next := range to[v] {
		if next == parent {
			continue
		}
		res += rec(next, v)
	}
	dp[v] = res
	return res
}

func modpow(x, y int64) int64 {
	if y == 0 {
		return 1
	}
	if y%2 != 0 {
		return x * modpow(x, y-1) % mod
	}
	tmp := modpow(x, y/2)
	return tmp * tmp % mod
}

type Scanner struct {
	r *bufio.Reader
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{
		r: bufio.NewReader(r),
	}
}

func (s *Scanner) next() string {
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

func (s *Scanner) nextInt() int {
	i, _ := strconv.Atoi(s.next())
	return i
}

// End of Code
