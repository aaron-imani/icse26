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
	fs := FastScanner{bufio.NewScanner(os.Stdin)}
	N := fs.nextInt()
	to = make([][]int, N)
	for i := 0; i < N; i++ {
		to[i] = []int{}
	}
	edges := make([][2]int, N-1)
	for i := 0; i < N-1; i++ {
		A := fs.nextInt() - 1
		B := fs.nextInt() - 1
		to[A] = append(to[A], B)
		to[B] = append(to[B], A)
		edges[i] = [2]int{B, A}
	}
	dp = make([]int, N)
	rec(0, -1)
	mulsum := int64(0)
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
		mulsum += mul
		mulsum %= mod
	}
	cases := modpow(2, int64(N))
	PN := (mulsum + (cases - 1 + mod) % mod) % mod
	BN := int64(N) * modpow(2, int64(N-1)) % mod
	WN := (PN - BN + mod) % mod
	ans := WN * modpow(cases, mod-2)
	ans %= mod
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

type FastScanner struct {
	scanner *bufio.Scanner
}

func (fs *FastScanner) next() string {
	if !fs.scanner.Scan() {
		panic("No more input")
	}
	return fs.scanner.Text()
}

func (fs *FastScanner) nextLine() string {
	if !fs.scanner.Scan() {
		panic("No more input")
	}
	return fs.scanner.Text()
}

func (fs *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(fs.next())
	return i
}

func (fs *FastScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(fs.next(), 10, 64)
	return i
}

func (fs *FastScanner) nextFloat64() float64 {
	f, _ := strconv.ParseFloat(fs.next(), 64)
	return f
}

func (fs *FastScanner) nextIntSlice(n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		slice[i] = fs.nextInt()
	}
	return slice
}

func (fs *FastScanner) nextLongSlice(n int) []int64 {
	slice := make([]int64, n)
	for i := 0; i < n; i++ {
		slice[i] = fs.nextLong()
	}
	return slice
}

func (fs *FastScanner) nextStringSlice(n int) []string {
	slice := make([]string, n)
	for i := 0; i < n; i++ {
		slice[i] = fs.next()
	}
	return slice
}

func (fs *FastScanner) nextFloat64Slice(n int) []float64 {
	slice := make([]float64, n)
	for i := 0; i < n; i++ {
		slice[i] = fs.nextFloat64()
	}
	return slice
}

func (fs *FastScanner) nextInt64Slice(n int) []int64 {
	slice := make([]int64, n)
	for i := 0; i < n; i++ {
		slice[i] = fs.nextLong()
	}
	return slice
}

func (fs *FastScanner) nextInt64Matrix(n, m int) [][]int64 {
	matrix := make([][]int64, n)
	for i := 0; i < n; i++ {
		matrix[i] = fs.nextInt64Slice(m)
	}
	return matrix
}

func (fs *FastScanner) nextStringMatrix(n, m int) [][]string {
	matrix := make([][]string, n)
	for i := 0; i < n; i++ {
		matrix[i] = fs.nextStringSlice(m)
	}
	return matrix
}

func (fs *FastScanner) nextIntMatrix(n, m int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = fs.nextIntSlice(m)
	}
	return matrix
}

func (fs *FastScanner) nextFloat64Matrix(n, m int) [][]float64 {
	matrix := make([][]float64, n)
	for i := 0; i < n; i++ {
		matrix[i] = fs.nextFloat64Slice(m)
	}
	return matrix
}

func (fs *FastScanner) nextInt64Triangle(n int) [][]int64 {
	triangle := make([][]int64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextInt64Slice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextStringTriangle(n int) [][]string {
	triangle := make([][]string, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextStringSlice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextIntTriangle(n int) [][]int {
	triangle := make([][]int, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextIntSlice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextFloat64Triangle(n int) [][]float64 {
	triangle := make([][]float64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextFloat64Slice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextInt64Triangle2(n int) [][]int64 {
	triangle := make([][]int64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextInt64Slice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextStringTriangle2(n int) [][]string {
	triangle := make([][]string, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextStringSlice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextIntTriangle2(n int) [][]int {
	triangle := make([][]int, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextIntSlice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextFloat64Triangle2(n int) [][]float64 {
	triangle := make([][]float64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextFloat64Slice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextInt64Triangle3(n int) [][]int64 {
	triangle := make([][]int64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextInt64Slice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextStringTriangle3(n int) [][]string {
	triangle := make([][]string, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextStringSlice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextIntTriangle3(n int) [][]int {
	triangle := make([][]int, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextIntSlice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextFloat64Triangle3(n int) [][]float64 {
	triangle := make([][]float64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextFloat64Slice(i + 1)
	}
	return triangle
}

func (fs *FastScanner) nextInt64Triangle4(n int) [][]int64 {
	triangle := make([][]int64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextInt64Slice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextStringTriangle4(n int) [][]string {
	triangle := make([][]string, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextStringSlice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextIntTriangle4(n int) [][]int {
	triangle := make([][]int, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextIntSlice(n - i)
	}
	return triangle
}

func (fs *FastScanner) nextFloat64Triangle4(n int) [][]float64 {
	triangle := make([][]float64, n)
	for i := 0; i < n; i++ {
		triangle[i] = fs.nextFloat64Slice(n - i)
	}
	return triangle
}

// End of Code
