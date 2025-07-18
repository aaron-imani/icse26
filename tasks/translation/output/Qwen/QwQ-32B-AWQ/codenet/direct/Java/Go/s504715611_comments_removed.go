package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{make([]int, n)}
	for i := range uf.Parent {
		uf.Parent[i] = -1
	}
	return uf
}

func (uf *UnionFind) root(a int) int {
	if uf.Parent[a] < 0 {
		return a
	}
	uf.Parent[a] = uf.root(uf.Parent[a])
	return uf.Parent[a]
}

func (uf *UnionFind) size(a int) int {
	return -uf.Parent[uf.root(a)]
}

func (uf *UnionFind) connect(a, b int) bool {
	rootA := uf.root(a)
	rootB := uf.root(b)
	if rootA == rootB {
		return false
	}
	if uf.size(rootA) < uf.size(rootB) {
		rootA, rootB = rootB, rootA
	}
	uf.Parent[rootA] += uf.Parent[rootB]
	uf.Parent[rootB] = rootA
	return true
}

type FastScanner struct {
	scanner *bufio.Scanner
}

var scan *FastScanner

func init() {
	scan = NewFastScanner()
}

func NewFastScanner() *FastScanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastScanner{scanner: sc}
}

func (fs *FastScanner) Next() string {
	if !fs.scanner.Scan() {
		return ""
	}
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	s := fs.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (fs *FastScanner) NextLong() int64 {
	s := fs.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

func (fs *FastScanner) NextDouble() float64 {
	s := fs.Next()
	n, _ := strconv.ParseFloat(s, 64)
	return n
}

func (fs *FastScanner) NextChar() rune {
	s := fs.Next()
	return []rune(s)[0]
}

var mod int64 = 1e9 + 7
const big = 2147483647
const PI = 3.14159265358979323846262338327950288

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func lmax(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func lmin(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func factorial(i int) int64 {
	if i == 1 {
		return 1
	}
	return int64(i) * factorial(i-1)
}

func gcd(a, b int64) int64 {
	if b > 0 {
		return gcd(b, a%b)
	}
	return a
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func modlcm(a, b int64) int64 {
	g := gcd(a, b)
	return a * b * modint(g, mod) % mod
}

func isPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	sqrt := int64(float64(n) * 0.5)
	for i := int64(3); i <= sqrt; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func upper_division(a, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func lupper_division(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(a int) []int {
	arr := make([]int, a)
	for i := 0; i < a; i++ {
		arr[i] = scan.NextInt()
	}
	return arr
}

func lsetArray(a int) []int64 {
	arr := make([]int64, a)
	for i := 0; i < a; i++ {
		arr[i] = scan.NextLong()
	}
	return arr
}

func reverse(str string) string {
	ch := []rune(str)
	for i, j := 0, len(ch)-1; i < j; i, j = i+1, j-1 {
		ch[i], ch[j] = ch[j], ch[i]
	}
	return string(ch)
}

func printArray(arr []int) {
	for i, v := range arr {
		if i < len(arr)-1 {
			fmt.Print(v, " ")
		} else {
			fmt.Println(v)
		}
	}
}

func doublesort(a [][]int) [][]int {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func ldoublesort(a [][]int64) [][]int64 {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func modpow(x, n, mod int64) int64 {
	sum := int64(1)
	for n > 0 {
		if (n & 1) == 1 {
			sum = sum * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return sum
}

func revch(ch []rune) []rune {
	for i, j := 0, len(ch)-1; i < j; i, j = i+1, j-1 {
		ch[i], ch[j] = ch[j], ch[i]
	}
	return ch
}

func revint(ch []int) []int {
	for i, j := 0, len(ch)-1; i < j; i, j = i+1, j-1 {
		ch[i], ch[j] = ch[j], ch[i]
	}
	return ch
}

func warshall_floyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if v[i][k]+v[k][j] < v[i][j] {
					v[i][j] = v[i][k] + v[k][j]
				}
			}
		}
	}
}

func modint(a, m int64) int64 {
	b, u, v := m, int64(1), int64(0)
	for b != 0 {
		t := a / b
		a, b = b, a-t*b
		u, v = v, u-t*v
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func lower_bound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
		mid := (right + left) / 2
		if a[mid] < key {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func upper_bound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
		mid := (right + left) / 2
		if a[mid] <= key {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func main() {
	str := scan.Next()
	if len(str) < 6 {
		fmt.Println("No")
		return
	}
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
