package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	mod  = int64(1e9 + 7)
	dx   = []int{-1, 0, 1, 0}
	dy   = []int{0, -1, 0, 1}
	dx8  = []int{-1, -1, -1, 0, 0, 1, 1, 1}
	dy8  = []int{-1, 0, 1, -1, 1, -1, 0, 1}
	inf  = int(^uint(0) >> 1)
	linf = int64(^uint(0) >> 1)
	dinf = float64(^uint(0) >> 1)
	eps  = 1e-10
	pi   = 3.14159265358979323846
	sb   = &strings.Builder{}
)

func solve() {
	tmp := ns()
	s := []rune(tmp)
	n := len(s)
	ans := 0
	cnt := 0
	for i := 0; i < n; i++ {
		if s[i] == 'S' {
			cnt++
		} else {
			if cnt == 0 {
				continue
			}
			ans++
			cnt--
		}
	}
	fmt.Println(n - 2*ans)
}

func reverse(ar []int) {
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func reverse(ar []int64) {
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func reverse(ar []float64) {
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func reverse(ar []rune) {
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func getReverse(s string) string {
	ar := []rune(s)
	reverse(ar)
	return string(ar)
}

func reverse(ls []interface{}) {
	n := len(ls)
	for i := 0; i < n/2; i++ {
		ls[i], ls[n-1-i] = ls[n-1-i], ls[i]
	}
}

func reverse(ar []interface{}) {
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func sbnl() {
	sb.WriteString("\n")
}

func lowerBound(a []int, x int) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBound(a []int, x int) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBound(a []int, x int) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBound(a []int, x int) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBound(a []int64, x int64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBound(a []int64, x int64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBound(a []int64, x int64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBound(a []int64, x int64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBound(a []float64, x float64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBound(a []float64, x float64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBound(a []float64, x float64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBound(a []float64, x float64) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBound(a []rune, x rune) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBound(a []rune, x rune) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBound(a []rune, x rune) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBound(a []rune, x rune) int {
	l, r := -1, len(a)
	for r-l > 1 {
		c := (l + r) / 2
		if a[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBound(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
		return -1
	}
	if ls[0] == nil {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int) >= x.(int)
		})
	case int64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int64) >= x.(int64)
		})
	case float64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(float64) >= x.(float64)
		})
	default:
		fmt.Println("lowerBound: non-numeric list being searched.")
		return -1
	}
}

func upperBound(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
		return -1
	}
	if ls[0] == nil {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int) > x.(int)
		})
	case int64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int64) > x.(int64)
		})
	case float64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(float64) > x.(float64)
		})
	default:
		fmt.Println("upperBound: non-numeric list being searched.")
		return -1
	}
}

func rupperBound(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
		return -1
	}
	if ls[0] == nil {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int) < x.(int)
		})
	case int64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int64) < x.(int64)
		})
	case float64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(float64) < x.(float64)
		})
	default:
		fmt.Println("rupperBound: non-numeric list being searched.")
		return -1
	}
}

func rlowerBound(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
		return -1
	}
	if ls[0] == nil {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int) <= x.(int)
		})
	case int64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(int64) <= x.(int64)
		})
	case float64:
		return ~sort.Search(len(ls), func(i int) bool {
			return ls[i].(float64) <= x.(float64)
		})
	default:
		fmt.Println("rlowerBound: non-numeric list being searched.")
		return -1
	}
}

func concat(x int, arr []int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concat(arr []int, x int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret, arr)
	ret[len(ret)-1] = x
	return ret
}

func concat(x int64, arr []int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concat(arr []int64, x int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret, arr)
	ret[len(ret)-1] = x
	return ret
}

func max(x int, y int) int {
	return int(math.Max(float64(x), float64(y)))
}

func min(x int, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

func max(x int, y int, z int) int {
	return int(math.Max(float64(x), math.Max(float64(y), float64(z))))
}

func min(x int, y int, z int) int {
	return int(math.Min(float64(x), math.Min(float64(y), float64(z))))
}

func max(x int64, y int64) int64 {
	return int64(math.Max(float64(x), float64(y)))
}

func min(x int64, y int64) int64 {
	return int64(math.Min(float64(x), float64(y)))
}

func max(x int64, y int64, z int64) int64 {
	return int64(math.Max(float64(x), math.Max(float64(y), float64(z))))
}

func min(x int64, y int64, z int64) int64 {
	return int64(math.Min(float64(x), math.Min(float64(y), float64(z))))
}

func max(x float64, y float64) float64 {
	return math.Max(x, y)
}

func min(x float64, y float64) float64 {
	return math.Min(x, y)
}

func max(x float64, y float64, z float64) float64 {
	return math.Max(x, math.Max(y, z))
}

func min(x float64, y float64, z float64) float64 {
	return math.Min(x, math.Min(y, z))
}

func sort(ar []int) {
	sort.Ints(ar)
}

func sort(ar []int64) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
}

func sort(ar []float64) {
	sort.Float64s(ar)
}

func sort(ar []rune) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
}

func rsort(ar []int) {
	sort.Ints(ar)
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func rsort(ar []int64) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func rsort(ar []float64) {
	sort.Float64s(ar)
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func rsort(ar []rune) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
	n := len(ar)
	for i := 0; i < n/2; i++ {
		ar[i], ar[n-1-i] = ar[n-1-i], ar[i]
	}
}

func fill(ar []int, x int) {
	for i := range ar {
		ar[i] = x
	}
}

func fill(ar []int64, x int64) {
	for i := range ar {
		ar[i] = x
	}
}

func fill(ar []bool, x bool) {
	for i := range ar {
		ar[i] = x
	}
}

func fill(ar []float64, x float64) {
	for i := range ar {
		ar[i] = x
	}
}

func fill(ar [][]int, x int) {
	for i := range ar {
		fill(ar[i], x)
	}
}

func fill(ar [][]int64, x int64) {
	for i := range ar {
		fill(ar[i], x)
	}
}

func fill(ar [][]float64, x float64) {
	for i := range ar {
		fill(ar[i], x)
	}
}

func fill(ar [][]bool, x bool) {
	for i := range ar {
		fill(ar[i], x)
	}
}

func plus(x int64, y int64) int64 {
	res := (x + y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func sub(x int64, y int64) int64 {
	res := (x - y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func mul(x int64, y int64) int64 {
	res := (x * y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func div(x int64, y int64) int64 {
	res := x * pow(y, mod-2) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func pow(x int64, y int64) int64 {
	if y < 0 {
		return 0
	}
	if y == 0 {
		return 1
	}
	if y%2 == 1 {
		return (x * pow(x, y-1)) % mod
	}
	root := pow(x, y/2)
	return (root * root) % mod
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	solve()
}

func ns() string {
	var s string
	fmt.Fscan(reader, &s)
	return s
}

func ni() int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}

func nl() int64 {
	var x int64
	fmt.Fscan(reader, &x)
	return x
}

func nd() float64 {
	var x float64
	fmt.Fscan(reader, &x)
	return x
}

func nc() rune {
	var c rune
	fmt.Fscan(reader, &c)
	return c
}

func na(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = ni()
	}
	return a
}

func nla(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nl()
	}
	return a
}

func nm(n int, m int) [][]rune {
	matrix := make([][]rune, n)
	for i := 0; i < n; i++ {
		matrix[i] = []rune(ns())
	}
	return matrix
}

// End of Code
