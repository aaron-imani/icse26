package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type UnionFind struct {
	parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{parent: make([]int, n)}
	for i := range uf.parent {
		uf.parent[i] = -1
	}
	return uf
}

func (uf *UnionFind) root(A int) int {
	if uf.parent[A] < 0 {
		return A
	}
	uf.parent[A] = uf.root(uf.parent[A])
	return uf.parent[A]
}

func (uf *UnionFind) size(A int) int {
	return -uf.parent[uf.root(A)]
}

func (uf *UnionFind) connect(A int, B int) bool {
	A = uf.root(A)
	B = uf.root(B)
	if A == B {
		return false
	}
	if uf.size(A) < uf.size(B) {
		A, B = B, A
	}
	uf.parent[A] += uf.parent[B]
	uf.parent[B] = A
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()
	fmt.Println(str[2] == str[3] && str[4] == str[5])
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

func isPrime(n int) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	d := int(math.Sqrt(float64(n)))
	for i := 3; i <= d; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func upperDivision(a int, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func lUpperDivision(a int64, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(a int) []int {
	b := make([]int, a)
	for i := 0; i < a; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}
	return b
}

func lSetArray(a int) []int64 {
	b := make([]int64, a)
	for i := 0; i < a; i++ {
		scanner.Scan()
		b[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	return b
}

func reverse(str string) string {
	ch := []rune(str)
	a := len(ch)
	for i := 0; i < upperDivision(a, 2); i++ {
		ch[i], ch[a-i-1] = ch[a-i-1], ch[i]
	}
	return string(ch)
}

func printArray(que []int) {
	for i := 0; i < len(que)-1; i++ {
		fmt.Print(que[i], " ")
	}
	fmt.Println(que[len(que)-1])
}

func doubleSort(a [][]int) [][]int {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func lDoubleSort(a [][]int64) [][]int64 {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func modPow(x int64, n int64, mo int64) int64 {
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

func modInt(a int64, m int64) int64 {
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

func max(a, b int) int {
	if a > b {
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

func lMax(a, b int64) int64 {
	if a > b {
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

func gcd(a, b int64) int64 {
	if b > 0 {
		return gcd(b, a%b)
	}
	return a
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func modLCM(a, b int64) int64 {
	return a * b * modInt(gcd(a, b), 1000000007)
}

// End of Code
