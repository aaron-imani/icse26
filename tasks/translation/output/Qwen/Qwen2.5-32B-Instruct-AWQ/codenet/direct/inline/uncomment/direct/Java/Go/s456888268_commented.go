package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	mod    = int64(1e9 + 7)
	dx     = []int{-1, 0, 1, 0}
	dy     = []int{0, -1, 0, 1}
	dx8    = []int{-1, -1, -1, 0, 0, 1, 1, 1}
	dy8    = []int{-1, 0, 1, -1, 1, -1, 0, 1}
	inf    = int(^uint(0) >> 1)
	linf   = int64(^uint(64) >> 1)
	dinf   = float64(^uint(64) >> 1)
	eps    = 1e-10
	pi     = math.Pi
	sb     strings.Builder
	is     = bufio.NewReader(os.Stdin)
	out    = bufio.NewWriter(os.Stdout)
	input  string
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
	fmt.Fprintln(out, n-2*ans)
}

func reverse[T any](ar []T) {
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func getReverse(s string) string {
	c := []rune(s)
	reverse(c)
	return string(c)
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

func lowerBound[T any](ls []T, x T) int {
	if len(ls) == 0 {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int) >= x.(int) })
	case int64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int64) >= x.(int64) })
	case float64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(float64) >= x.(float64) })
	default:
		panic("Unsupported type for binary search")
	}
}

func upperBound[T any](ls []T, x T) int {
	if len(ls) == 0 {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int) > x.(int) })
	case int64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int64) > x.(int64) })
	case float64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(float64) > x.(float64) })
	default:
		panic("Unsupported type for binary search")
	}
}

func rupperBound[T any](ls []T, x T) int {
	if len(ls) == 0 {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int) < x.(int) })
	case int64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int64) < x.(int64) })
	case float64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(float64) < x.(float64) })
	default:
		panic("Unsupported type for binary search")
	}
}

func rlowerBound[T any](ls []T, x T) int {
	if len(ls) == 0 {
		return -1
	}
	switch ls[0].(type) {
	case int:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int) <= x.(int) })
	case int64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(int64) <= x.(int64) })
	case float64:
		return ~sort.Search(len(ls), func(i int) bool { return ls[i].(float64) <= x.(float64) })
	default:
		panic("Unsupported type for binary search")
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
	copy(ret[:len(ret)-1], arr)
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
	copy(ret[:len(ret)-1], arr)
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

func sortInt(ar []int) {
	sort.Ints(ar)
}

func sortInt64(ar []int64) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
}

func sortFloat64(ar []float64) {
	sort.Float64s(ar)
}

func sortRune(ar []rune) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
}

func rsortInt(ar []int) {
	sort.Ints(ar)
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rsortInt64(ar []int64) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rsortFloat64(ar []float64) {
	sort.Float64s(ar)
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rsortRune(ar []rune) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func fillInt(arr []int, x int) {
	for i := range arr {
		arr[i] = x
	}
}

func fillInt64(arr []int64, x int64) {
	for i := range arr {
		arr[i] = x
	}
}

func fillBool(arr []bool, x bool) {
	for i := range arr {
		arr[i] = x
	}
}

func fillFloat64(arr []float64, x float64) {
	for i := range arr {
		arr[i] = x
	}
}

func fillIntMatrix(arr [][]int, x int) {
	for i := range arr {
		fillInt(arr[i], x)
	}
}

func fillInt64Matrix(arr [][]int64, x int64) {
	for i := range arr {
		fillInt64(arr[i], x)
	}
}

func fillFloat64Matrix(arr [][]float64, x float64) {
	for i := range arr {
		fillFloat64(arr[i], x)
	}
}

func fillBoolMatrix(arr [][]bool, x bool) {
	for i := range arr {
		fillBool(arr[i], x)
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
	return root * root % mod
}

func main() {
	defer out.Flush()
	solve()
}

func ns() string {
	line, _ := is.ReadString('\n')
	return strings.TrimSpace(line)
}

func ni() int {
	line, _ := is.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

func nl() int64 {
	line, _ := is.ReadString('\n')
	i, _ := strconv.ParseInt(strings.TrimSpace(line), 10, 64)
	return i
}
End of Code.
