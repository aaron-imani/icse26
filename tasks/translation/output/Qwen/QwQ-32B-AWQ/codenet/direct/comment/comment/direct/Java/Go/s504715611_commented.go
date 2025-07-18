package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"sort"
)

const (
	mod      = 1e9 + 7
	eps      = 1.0e-14
	big      = int(^uint(0) >> 1)
.PI       = 3.14159265358979323846262338327950288
)

var scan *bufio.Scanner

func init() {
	scan = bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)
}

func Next() string {
	if !scan.Scan() {
		panic("No more input")
	}
	return scan.Text()
}

func NextInt() int {
	i, _ := strconv.Atoi(Next())
	return i
}

func NextLong() int64 {
	s := Next()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

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
	root := uf.Root(uf.Parent[a])
	uf.Parent[a] = root
	return root
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

func LowerBound(a []int, key int) int {
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

func UpperBound(a []int, key int) int {
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

func IsPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	d := math.Sqrt(float64(n))
	for i := int64(3); i <= int64(d); i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func UpperDivision(a, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func LUpperDivision(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func SetArray(a int) []int {
	arr := make([]int, a)
	for i := range arr {
		arr[i] = NextInt()
	}
	return arr
}

func LSetArray(a int) []int64 {
	arr := make([]int64, a)
	for i := range arr {
		arr[i] = NextLong()
	}
	return arr
}

func Reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func PrintArray(arr []int) {
	for i, v := range arr {
		if i < len(arr)-1 {
			fmt.Print(v, " ")
		} else {
			fmt.Println(v)
		}
	}
}

func DoubleSort(a [][]int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
}

func LDoublesort(a [][]int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
}

func ModPow(x, n, mo int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mo
		}
		x = x * x % mo
		n >>= 1
	}
	return res
}

func RevCh(ch []rune) []rune {
	reversed := make([]rune, len(ch))
	for i, j := 0, len(ch)-1; i < len(ch); i, j = i+1, j-1 {
		reversed[i] = ch[j]
	}
	return reversed
}

func RevInt(ch []int) []int {
	reversed := make([]int, len(ch))
	for i, j := 0, len(ch)-1; i < len(ch); i, j = i+1, j-1 {
		reversed[i] = ch[j]
	}
	return reversed
}

func WarshallFloyd(v [][]int, n int) {
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

func GCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

func ModInt(a, m int64) int64 {
	var u, v int64 = 1, 0
	b := m
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

func main() {
	str := Next()
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
