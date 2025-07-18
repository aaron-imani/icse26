package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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

func (uf *UnionFind) Root(a int) int {
	if uf.Parent[a] < 0 {
		return a
	}
	uf.Parent[a] = uf.Root(uf.Parent[a])
	return uf.Parent[a]
}

func (uf *UnionFind) Size(a int) int {
	return -uf.Parent[uf.Root(a)]
}

func (uf *UnionFind) Connect(a, b int) bool {
	a = uf.Root(a)
	b = uf.Root(b)
	if a == b {
		return false
	}
	if uf.Size(a) < uf.Size(b) {
		a, b = b, a
	}
	uf.Parent[a] += uf.Parent[b]
	uf.Parent[b] = a
	return true
}

var (
	scanner = bufio.NewScanner(os.Stdin)
	reader  = strings.NewReader("")
)

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	scanner.Scan()
	i, _ := strconv.Atoi(scanner.Text())
	return i
}

func nextLong() int64 {
	scanner.Scan()
	i, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return i
}

func nextFloat() float64 {
	scanner.Scan()
	i, _ := strconv.ParseFloat(scanner.Text(), 64)
	return i
}

func main() {
	scanner.Split(bufio.ScanWords)
	str := nextString()
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
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
	left := 0
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
	d := int64(float64(n) ** 0.5)
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

func lUpperDivision(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(a int) []int {
	b := make([]int, a)
	for i := 0; i < a; i++ {
		b[i] = nextInt()
	}
	return b
}

func lSetArray(a int) []int64 {
	b := make([]int64, a)
	for i := 0; i < a; i++ {
		b[i] = nextLong()
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

func printArray(que []int) {
	for i := 0; i < len(que)-1; i++ {
		fmt.Print(que[i], " ")
	}
	fmt.Println(que[len(que)-1])
}

func doubleSort(a [][]int) [][]int {
	return a
}

func lDoubleSort(a [][]int64) [][]int64 {
	return a
}

func modPow(x, n, mo int64) int64 {
	sum := int64(1)
	for n > 0 {
		if n&1 == 1 {
			sum = sum * x % mo
		}
		x = x * x % mo
		n >>= 1
	}
	return sum
}

func revCh(ch []rune) []rune {
	ret := make([]rune, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
	}
	return ret
}

func revInt(ch []int) []int {
	ret := make([]int, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
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

func modInt(a, m int64) int64 {
	b := m
	u := int64(1)
	v := int64(0)
	for b != 0 {
		t := a / b
		a -= t * b
		x := a
		a = b
		b = x

		u -= t * v
		x = u
		u = v
		v = x
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func lMin(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lMax(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
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

func modLcm(a, b, mod int64) int64 {
	return a * b * modInt(gcd(a, b), mod) % mod
}

// End of Code
