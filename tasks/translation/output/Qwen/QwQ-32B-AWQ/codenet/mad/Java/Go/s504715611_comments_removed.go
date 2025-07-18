package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	if uf.Size(a) < uf.Size(b) {
		a, b = b, a
		rootA, rootB = rootB, rootA
	}
	uf.Parent[rootA] += uf.Parent[rootB]
	uf.Parent[rootB] = rootA
	return true
}

type FastScanner struct {
	reader *bufio.Reader
	buffer []byte
	ptr    int
	buflen int
}

const mod int64 = 1e9 + 7

func NewFastScanner() *FastScanner {
	return &FastScanner{
		reader: bufio.NewReaderSize(os.Stdin, 1024),
		buffer: make([]byte, 1024),
		ptr:    0,
		buflen: 0,
	}
}

func (fs *FastScanner) hasNextByte() bool {
	if fs.ptr < fs.buflen {
		return true
	}
	fs.ptr = 0
	var err error
	fs.buflen, err = fs.reader.Read(fs.buffer)
	if err != nil || fs.buflen == 0 {
		return false
	}
	return true
}

func (fs *FastScanner) readByte() byte {
	if !fs.hasNextByte() {
		return 255
	}
	b := fs.buffer[fs.ptr]
	fs.ptr++
	return b
}

func (fs *FastScanner) hasNext() bool {
	for fs.hasNextByte() {
		b := fs.buffer[fs.ptr]
		if b >= 33 && b <= 126 {
			return true
		}
		fs.ptr++
	}
	return false
}

func (fs *FastScanner) Next() string {
	if !fs.hasNext() {
		panic("No element found")
	}
	start := fs.ptr
Loop:
	for {
		b := fs.readByte()
		if b == 255 {
			break Loop
		}
		if b < 33 || b > 126 {
			break Loop
		}
	}
	end := fs.ptr - 1
	return string(fs.buffer[start:end])
}

func (fs *FastScanner) NextInt() int {
	s := fs.Next()
	num, _ := strconv.Atoi(s)
	return num
}

func (fs *FastScanner) NextLong() int64 {
	s := fs.Next()
	num, _ := strconv.ParseInt(s, 10, 64)
	return num
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
	sqrtN := math.Sqrt(float64(n))
	for i := int64(3); i <= int64(sqrtN); i += 2 {
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

func SetArray(n int, fs *FastScanner) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.NextInt()
	}
	return arr
}

func LSetArray(n int, fs *FastScanner) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = fs.NextLong()
	}
	return arr
}

func Reverse(str string) string {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func PrintArray(arr []int) {
	for i, v := range arr {
		if i < len(arr)-1 {
			fmt.Printf("%d ", v)
		} else {
			fmt.Printf("%d\n", v)
		}
	}
}

func DoubleSort(a [][]int) [][]int {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func LDoubleSort(a [][]int64) [][]int64 {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func ModPow(x, n, mo int64) int64 {
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

func WarshallFloyd(v [][]int, n int) {
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

func GCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

func LCM(a, b int64) int64 {
	return a * b / GCD(a, b)
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func LMax(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func LMin(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func Factorial(i int) int {
	if i == 1 {
		return 1
	}
	return i * Factorial(i-1)
}

func ModLCM(a, b int64) int64 {
	g := GCD(a, b)
	return a * b * ModInt(g, mod)
}

func main() {
	fs := NewFastScanner()
	str := fs.Next()
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
