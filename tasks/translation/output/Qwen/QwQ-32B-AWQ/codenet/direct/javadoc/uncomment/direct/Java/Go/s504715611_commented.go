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
	mod      = 1e9 + 7
	eps      = 1.0e-14
	big      = 2147483647
	PI       = 3.14159265358979323846262338327950288
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

func (uf *UnionFind) root(A int) int {
	if uf.Parent[A] < 0 {
		return A
	}
	uf.Parent[A] = uf.root(uf.Parent[A])
	return uf.Parent[A]
}

func (uf *UnionFind) size(A int) int {
	return -uf.Parent[uf.root(A)]
}

func (uf *UnionFind) connect(A, B int) bool {
	aRoot := uf.root(A)
	bRoot := uf.root(B)
	if aRoot == bRoot {
		return false
	}
	if uf.size(A) < uf.size(B) {
		aRoot, bRoot = bRoot, aRoot
	}
	uf.Parent[aRoot] += uf.Parent[bRoot]
	uf.Parent[bRoot] = aRoot
	return true
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func modinv(a, m int64) int64 {
	b := m
	u, v := int64(1), int64(0)
	for b != 0 {
		t := a / b
		temp := a - t*b
		a, b = b, temp
		tempu := u - t*v
		u, v = v, tempu
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func modlcm(a, b int64) int64 {
	g := gcd(a, b)
	return a * b / g * modinv(g, mod) % mod
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
	return a
}

func lmin(a, b int64) int64 {
	return b
}

func factorial(n int) int {
	if n == 1 {
		return 1
	}
	return n * factorial(n-1)
}

func lowerBound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
		mid := (left + right) / 2
		if a[mid] < key {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func upperBound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
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

func setArray(scanner *bufio.Scanner, n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		arr[i] = num
	}
	return arr
}

func lsetArray(scanner *bufio.Scanner, n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		arr[i] = num
	}
	return arr
}

func reverse(str string) string {
	runes := []rune(str)
	n := len(runes)
	for i := 0; i < (n+1)/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]
	}
	return string(runes)
}

func printArray(arr []int) {
	if len(arr) == 0 {
		return
	}
	for i := 0; i < len(arr)-1; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Println(arr[len(arr)-1])
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

func modpow(x, n, mo int64) int64 {
	result := int64(1)
	for n > 0 {
		if n&1 == 1 {
			result = result * x % mo
		}
		x = x * x % mo
		n >>= 1
	}
	return result
}

func revch(ch []rune) []rune {
	ret := make([]rune, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
	}
	return ret
}

func warshallFloyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if v[i][j] > v[i][k]+v[k][j] {
					v[i][j] = v[i][k] + v[k][j]
				}
			}
		}
	}
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
