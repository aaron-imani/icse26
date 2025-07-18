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
	rootA := uf.root(A)
	rootB := uf.root(B)
	if rootA == rootB {
		return false
	}
	if uf.size(A) < uf.size(B) {
		A, B = B, A
		rootA, rootB = rootB, rootA
	}
	uf.Parent[rootA] += uf.Parent[rootB]
	uf.Parent[rootB] = rootA
	return true
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

func factorial(i int) int {
	if i == 1 {
		return 1
	}
	return i * factorial(i-1)
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

func modint(a, m int64) int64 {
	b := m
	var u, v int64 = 1, 0
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

func setArray(a int, sc *bufio.Scanner) []int {
	res := make([]int, a)
	for i := 0; i < a; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		res[i] = num
	}
	return res
}

func lsetArray(a int, sc *bufio.Scanner) []int64 {
	res := make([]int64, a)
	for i := 0; i < a; i++ {
		sc.Scan()
		num, _ := strconv.ParseInt(sc.Text(), 10, 64)
		res[i] = num
	}
	return res
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func revch(ch []rune) string {
	reversed := make([]rune, len(ch))
	for i, j := 0, len(ch)-1; i < len(ch); i, j = i+1, j-1 {
		reversed[i] = ch[j]
	}
	return string(reversed)
}

func revint(arr []int) []int {
	reversed := make([]int, len(arr))
	for i, j := 0, len(arr)-1; i < len(arr); i, j = i+1, j-1 {
		reversed[i] = arr[j]
	}
	return reversed
}

func warshall_floyd(v [][]int, n int) {
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

func doublesort(a [][]int) [][]int {
	sort.Slice(a, func(i, j int) bool { return a[i][0] < a[j][0] })
	return a
}

func ldoublesort(a [][]int64) [][]int64 {
	sort.Slice(a, func(i, j int) bool { return a[i][0] < a[j][0] })
	return a
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
