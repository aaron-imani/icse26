package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
	"strings"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{Parent: make([]int, n)}
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

func (uf *UnionFind) connect(A int, B int) bool {
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

var (
	scan = bufio.NewScanner(os.Stdin)
	rand = rand.NewSource(time.Now().UnixNano())
	mod  = 1000000007
	eps  = 1.0E-14
	big  = math.MaxInt32
	PI   = 3.14159265358979323846262338327950288
)

func modlcm(a int64, b int64) int64 {
	return a * b * modint(gcd(a, b), mod)
}

func gcd(a int64, b int64) int64 {
	if b > 0 {
		return gcd(b, a%b)
	}
	return a
}

func lcm(a int64, b int64) int64 {
	return a * b / gcd(a, b)
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func lmax(a int64, b int64) int64 {
	return math.Max(a, b)
}

func lmin(a int64, b int64) int64 {
	return math.Min(a, b)
}

func factorial(i int) int {
	if i == 1 {
		return 1
	}
	return i * factorial(i-1)
}

func main() {
	scan.Scan()
	str := scan.Text()
	fmt.Println(str[2] == str[3] && str[4] == str[5])
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
	d := math.Sqrt(float64(n))
	for i := int64(3); i <= d; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func upper_division(a int, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func lupper_division(a int64, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(a int) []int {
	b := make([]int, a)
	for i := 0; i < a; i++ {
		scan.Scan()
		b[i], _ = strconv.Atoi(scan.Text())
	}
	return b
}

func lsetArray(a int) []int64 {
	b := make([]int64, a)
	for i := 0; i < a; i++ {
		scan.Scan()
		b[i], _ = strconv.ParseInt(scan.Text(), 10, 64)
	}
	return b
}

func reverse(str string) string {
	ch := []rune(str)
	a := len(ch)
	for i := 0; i < upper_division(a, 2); i++ {
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

func modpow(x int64, n int64, mo int64) int64 {
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

func warshall_floyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				v[i][j] = min(v[i][j], v[i][k]+v[k][j])
			}
		}
	}
}

func modint(a int64, m int64) int64 {
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

type FastScanner struct {
	reader *bufio.Reader
}

func NewFastScanner() *FastScanner {
	return &FastScanner{reader: bufio.NewReader(os.Stdin)}
}

func (fs *FastScanner) hasNext() bool {
	if fs.reader.Buffered() > 0 {
		return true
	}
	return false
}

func (fs *FastScanner) next() string {
	if !fs.hasNext() {
		panic("No more input")
	}
	str, _ := fs.reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func (fs *FastScanner) nextLong() int64 {
	if !fs.hasNext() {
		panic("No more input")
	}
	str := fs.next()
	n, _ := strconv.ParseInt(str, 10, 64)
	return n
}

func (fs *FastScanner) nextInt() int {
	if !fs.hasNext() {
		panic("No more input")
	}
	str := fs.next()
	n, _ := strconv.Atoi(str)
	return n
}

func (fs *FastScanner) nextDouble() float64 {
	if !fs.hasNext() {
		panic("No more input")
	}
	str := fs.next()
	n, _ := strconv.ParseFloat(str, 64)
	return n
}

func (fs *FastScanner) nextChar() rune {
	if !fs.hasNext() {
		panic("No more input")
	}
	str := fs.next()
	return []rune(str)[0]
}

// End of Code
