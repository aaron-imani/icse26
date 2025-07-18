package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{
		Parent: make([]int, n),
	}
	for i := range uf.Parent {
		uf.Parent[i] = -1
	}
	return uf
}

func (uf *UnionFind) Root(a int) int {
	if uf.Parent[a] < 0 {
		return a
	}
	rootParent := uf.Root(uf.Parent[a])
	uf.Parent[a] = rootParent
	return rootParent
}

func (uf *UnionFind) Size(a int) int {
	return -uf.Parent[uf.Root(a)]
}

func (uf *UnionFind) Connect(a, b int) bool {
	rootA := uf.Root(a)
	rootB := uf.Root(b)
	if rootA == rootB {
		return false
	}
	if uf.Size(rootA) < uf.Size(rootB) {
		rootA, rootB = rootB, rootA
	}
	uf.Parent[rootA] += uf.Parent[rootB]
	uf.Parent[rootB] = rootA
	return true
}

const (
	mod          int64 = 1e9 + 7
	modInt       int   = 1000000007
	big          int   = int(^uint(0) >> 1)
	PI           float64 = 3.14159265358979323846262338327950288
)

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
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func modlcm(a, b int64) int64 {
	g := gcd(a, b)
	invG := modint(g, modInt)
	return a * b % modInt * invG % modInt
}

func modint(a, m int) int {
	b := m
	var u, v int = 1, 0
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

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastScanner{scanner: sc}
}

func (fs *FastScanner) Next() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	token := fs.Next()
	num, _ := strconv.Atoi(token)
	return num
}

func (fs *FastScanner) NextLong() int64 {
	token := fs.Next()
	num, _ := strconv.ParseInt(token, 10, 64)
	return num
}

func (fs *FastScanner) NextDouble() float64 {
	token := fs.Next()
	num, _ := strconv.ParseFloat(token, 64)
	return num
}

func (fs *FastScanner) NextChar() rune {
	token := fs.Next()
	return []rune(token)[0]
}

var scan = NewFastScanner()

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
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func printArray(que []int) {
	for i, num := range que {
		if i < len(que)-1 {
			fmt.Print(num, " ")
		} else {
			fmt.Println(num)
		}
	}
}

func doublesort(a [][]int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
}

func ldoublesort(a [][]int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
}

func modpow(x, n, mo int64) int64 {
	res := int64(1)
	for n > 0 {
		if n%2 == 1 {
			res = res * x % mo
		}
		x = x * x % mo
		n = n / 2
	}
	return res
}

func revch(ch []rune) []rune {
	n := len(ch)
	ret := make([]rune, n)
	for i, j := 0, n-1; i < n; i, j = i+1, j-1 {
		ret[i] = ch[j]
	}
	return ret
}

func revint(ch []int) []int {
	n := len(ch)
	ret := make([]int, n)
	for i, j := 0, n-1; i < n; i, j = i+1, j-1 {
		ret[i] = ch[j]
	}
	return ret
}

func warshall_floyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				v[i][j] = min(v[i][j], v[i][k]+v[k][j])
			}
		}
	}
}

func lower_bound(a []int, key int) int {
	left, right := 0, len(a)
	for left < right-1 {
		mid := (left + right) / 2
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
	for left < right-1 {
		mid := (left + right) / 2
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
	sqrt := math.Sqrt(float64(n))
	for i := int64(3); i <= int64(sqrt); i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
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
