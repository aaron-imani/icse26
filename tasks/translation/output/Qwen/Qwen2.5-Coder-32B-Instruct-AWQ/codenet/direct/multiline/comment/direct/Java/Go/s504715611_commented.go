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
	r       = strings.NewReader("")
	w       = bufio.NewWriter(os.Stdout)
	mod     = 1000000007
	eps     = 1.0e-14
	big     = int(^uint(0) >> 1)
	PI      = 3.14159265358979323846262338327950288
)

func main() {
	defer w.Flush()
	scanner.Scan()
	str := scanner.Text()
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Fprintln(w, "Yes")
	} else {
		fmt.Fprintln(w, "No")
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
		b[i] = nextInt64()
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
		fmt.Fprintf(w, "%d ", que[i])
	}
	fmt.Fprintln(w, que[len(que)-1])
}

func doublesort(a [][]int) [][]int {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i][0] > a[j][0] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}
	return a
}

func ldoublesort(a [][]int64) [][]int64 {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i][0] > a[j][0] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}
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
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
	}
	return ret
}

func revint(ch []int) []int {
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
				if v[i][j] > v[i][k]+v[k][j] {
					v[i][j] = v[i][k] + v[k][j]
				}
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

func nextLine() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextLine())
	return i
}

func nextInt64() int64 {
	i, _ := strconv.ParseInt(nextLine(), 10, 64)
	return i
}

func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(nextLine(), 64)
	return f
}

// End of Code
