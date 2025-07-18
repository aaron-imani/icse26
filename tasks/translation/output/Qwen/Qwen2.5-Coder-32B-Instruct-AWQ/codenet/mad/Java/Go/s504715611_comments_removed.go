package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
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
	A = uf.root(A)
	B = uf.root(B)
	if A == B {
		return false
	}
	if uf.size(A) < uf.size(B) {
		A, B = B, A
	}
	uf.Parent[A] += uf.Parent[B]
	uf.Parent[B] = A
	return true
}

const (
	mod = 1000000007
	eps = 1.0e-14
	big = int(^uint(0) >> 1)
	PI  = 3.14159265358979323846264338327950288
)

func modlcm(a, b int64) int64 {
	return a * b * modint(gcd(a, b), mod)
}

func gcd(a, b int64) int64 {
	for b > 0 {
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

func lower_bound(a []int, key int) int {
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

func upper_bound(a []int, key int) int {
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
	d := int64(math.Sqrt(float64(n)))
	for i := int64(3); i <= d; i += 2 {
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
	b := make([]int, a)
	for i := range b {
		b[i] = nextInt()
	}
	return b
}

func lsetArray(a int) []int64 {
	b := make([]int64, a)
	for i := range b {
		b[i] = nextLong()
	}
	return b
}

func reverse(str string) string {
	ch := []rune(str)
	a := len(ch)
	for i := 0; i < upper_division(a, 2); i++ {
		ch[i], ch[a-1-i] = ch[a-1-i], ch[i]
	}
	return string(ch)
}

func printArray(que []int) {
	for i := 0; i < len(que)-1; i++ {
		fmt.Printf("%d ", que[i])
	}
	fmt.Println(que[len(que)-1])
}

func doublesort(a [][]int) [][]int {
	return a
}

func ldoublesort(a [][]int64) [][]int64 {
	return a
}

func modpow(x, n, mo int64) int64 {
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

func revch(ch []rune) []rune {
	ret := make([]rune, len(ch))
	for i := len(ch) - 1; i >= 0; i-- {
		ret[len(ch)-1-i] = ch[i]
	}
	return ret
}

func revint(ch []int) []int {
	ret := make([]int, len(ch))
	for i := len(ch) - 1; i >= 0; i-- {
		ret[len(ch)-1-i] = ch[i]
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

func modint(a, m int64) int64 {
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

var (
	scanner = bufio.NewScanner(os.Stdin)
)

func nextLine() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextLine())
	return i
}

func nextLong() int64 {
	i, _ := strconv.ParseInt(nextLine(), 10, 64)
	return i
}

func nextFloat() float64 {
	i, _ := strconv.ParseFloat(nextLine(), 64)
	return i
}

func nextString() string {
	return nextLine()
}

func main() {
	scanner.Split(bufio.ScanWords)
	str := nextString()
	if len(str) > 5 && str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
