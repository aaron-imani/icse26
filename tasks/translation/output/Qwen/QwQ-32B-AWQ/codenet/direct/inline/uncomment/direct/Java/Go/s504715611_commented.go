package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

const (
	mod          = 1000000007
	eps          = 1.0e-14
	big          = 2147483647 // which is int's max
	PI           = 3.14159265358979323846262338327950288
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	parent := make([]int, n)
	for i := range parent {
		parent[i] = -1
	}
	return &UnionFind{Parent: parent}
}

func (uf *UnionFind) root(a int) int {
	if uf.Parent[a] < 0 {
		return a
	}
	root := uf.root(uf.Parent[a])
	uf.Parent[a] = root // path compression
	return root
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
	if uf.size(a) < uf.size(b) {
		rootA, rootB = rootB, rootA // swap
	}
	uf.Parent[rootA] += uf.Parent[rootB]
	uf.Parent[rootB] = rootA
	return true
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

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

func lowerBound(a []int, key int) int {
	right := len(a)
	left := 0
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

func upperBound(a []int, key int) int {
	right := len(a)
	left := .0
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

func isPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	d := int64(math.Sqrt(float64(n)))
	for i := int64(3); i <= d; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func upperDivision(a, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func lupperDivision(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(scanner *bufio.Scanner, a int) []int {
	b := make([]int, a)
	for i := 0; i < a; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		b[i] = num
	}
	return b
}

func lsetArray(scanner *bufio.Scanner, a int) []int64 {
	b := make([]int64, a)
	for i := 0; i < a; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		b[i] = num
	}
	return b
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func printArray(arr []int) {
	for i := 0; i < len(arr)-1; i++ {
		fmt.Print(arr[i], " ")
	}
	fmt.Println(arr[len(arr)-1])
}

type IntMatrix [][]int

func (a IntMatrix) Len() int           { return len(a) }
func (a IntMatrix) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a IntMatrix) Less(i, j int) bool { return a[i][0] < a[j][0] }

func doublesort(a [][]int) [][]int {
	sort.Sort(IntMatrix(a))
	return a
}

type LongMatrix [][]int64

func (a LongMatrix) Len() int           { return len(a) }
func (a LongMatrix) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a LongMatrix) Less(i, j int) bool { return a[i][0] < a[j][0] }

func ldoublesort(a [][]int64) [][]int64 {
	sort.Sort(LongMatrix(a))
	return a
}

func modpow(x, n, mo int64) int64 {
	sum := int64(1)
	for n > 0 {
		if (n & 1) == 1 {
			sum = sum * x % mo
		}
		x = x * x % mo
		n >>= 1
	}
	return sum
}

func revch(ch []rune) []rune {
	ret := make([]rune, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i-- {
		ret[j] = ch[i]
		j++
	}
	return ret
}

func revint(ch []int) []int {
	ret := make([]int, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i-- {
		ret[j] = ch[i]
		j++
	}
	return ret
}

func warshallFloyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				v[i][j] = min(v[i][j], v[i][k]+v[k][j])
			}
		}
	}
}

func modint(a, m int64) int64 {
	b := m
	u, v := int64(1), int64(0)
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

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner(reader *bufio.Reader) *FastScanner {
	sc := bufio.NewScanner(reader)
	sc.Split(bufio.ScanWords)
	return &FastScanner{sc: sc}
}

func (fs *FastScanner) Next() bool {
	return fs.sc.Scan()
}

func (fs *FastScanner) Text() string {
	return fs.sc.Text()
}

func (fs *FastScanner) NextInt() int {
	fs.Next()
	num, _ := strconv.Atoi(fs.Text())
	return num
}

func (fs *FastScanner) NextLong() int64 {
	fs.Next()
	num, _ := strconv.ParseInt(fs.Text(), 10, 64)
	return num
}

func (fs *FastScanner) NextDouble() float64 {
	fs.Next()
	num, _ := strconv.ParseFloat(fs.Text(), 64)
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()
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
