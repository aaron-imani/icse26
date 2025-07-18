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
	linf   = int64(^uint(0) >> 1)
	dinf   = float64(^uint(0) >> 1)
	eps    = 1e-10
	pi     = 3.14159265358979323846
	sb     strings.Builder
	reader *bufio.Reader
	writer *bufio.Writer
)

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	solve()
}

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
	fmt.Fprintf(writer, "%d\n", n-2*ans)
}

func reverse(ar []int) {
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func reverseL(ar []int64) {
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func reverseD(ar []float64) {
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func reverseR(ar []rune) {
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func getReverse(s string) string {
	c := []rune(s)
	reverseR(c)
	return string(c)
}

func reverseList[T any](ls []T) {
	length := len(ls)
	for i := 0; i < length/2; i++ {
		ls[i], ls[length-1-i] = ls[length-1-i], ls[i]
	}
}

func sbnl() {
	sb.WriteString("\n")
}

func lowerBound(ar []int, x int) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBound(ar []int, x int) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBound(ar []int, x int) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBound(ar []int, x int) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBoundL(ar []int64, x int64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBoundL(ar []int64, x int64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBoundL(ar []int64, x int64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBoundL(ar []int64, x int64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBoundD(ar []float64, x float64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBoundD(ar []float64, x float64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBoundD(ar []float64, x float64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBoundD(ar []float64, x float64) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBoundR(ar []rune, x rune) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBoundR(ar []rune, x rune) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBoundR(ar []rune, x rune) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBoundR(ar []rune, x rune) int {
	l, r := -1, len(ar)
	for r-l > 1 {
		c := (l + r) / 2
		if ar[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func lowerBoundList[T comparable](ls []T, x T) int {
	l, r := -1, len(ls)
	for r-l > 1 {
		c := (l + r) / 2
		if ls[c] < x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func upperBoundList[T comparable](ls []T, x T) int {
	l, r := -1, len(ls)
	for r-l > 1 {
		c := (l + r) / 2
		if ls[c] <= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rlowerBoundList[T comparable](ls []T, x T) int {
	l, r := -1, len(ls)
	for r-l > 1 {
		c := (l + r) / 2
		if ls[c] > x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func rupperBoundList[T comparable](ls []T, x T) int {
	l, r := -1, len(ls)
	for r-l > 1 {
		c := (l + r) / 2
		if ls[c] >= x {
			l = c
		} else {
			r = c
		}
	}
	return r
}

func concat(x int, arr []int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concatArr(arr []int, x int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret[:len(arr)], arr)
	ret[len(arr)] = x
	return ret
}

func concatL(x int64, arr []int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concatArrL(arr []int64, x int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret[:len(arr)], arr)
	ret[len(arr)] = x
	return ret
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

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func maxL(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func minL(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max3L(a, b, c int64) int64 {
	return maxL(maxL(a, b), c)
}

func min3L(a, b, c int64) int64 {
	return minL(minL(a, b), c)
}

func maxD(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func minD(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func max3D(a, b, c float64) float64 {
	return maxD(maxD(a, b), c)
}

func min3D(a, b, c float64) float64 {
	return minD(minD(a, b), c)
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

func rSortInt(ar []int) {
	sort.Ints(ar)
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rSortInt64(ar []int64) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rSortFloat64(ar []float64) {
	sort.Float64s(ar)
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func rSortRune(ar []rune) {
	sort.Slice(ar, func(i, j int) bool { return ar[i] < ar[j] })
	length := len(ar)
	for i := 0; i < length/2; i++ {
		ar[i], ar[length-1-i] = ar[length-1-i], ar[i]
	}
}

func fillInt(ar []int, x int) {
	for i := range ar {
		ar[i] = x
	}
}

func fillInt64(ar []int64, x int64) {
	for i := range ar {
		ar[i] = x
	}
}

func fillBool(ar []bool, x bool) {
	for i := range ar {
		ar[i] = x
	}
}

func fillFloat64(ar []float64, x float64) {
	for i := range ar {
		ar[i] = x
	}
}

func fillIntMatrix(ar [][]int, x int) {
	for i := range ar {
		fillInt(ar[i], x)
	}
}

func fillInt64Matrix(ar [][]int64, x int64) {
	for i := range ar {
		fillInt64(ar[i], x)
	}
}

func fillFloat64Matrix(ar [][]float64, x float64) {
	for i := range ar {
		fillFloat64(ar[i], x)
	}
}

func fillBoolMatrix(ar [][]bool, x bool) {
	for i := range ar {
		fillBool(ar[i], x)
	}
}

func plus(x, y int64) int64 {
	res := (x + y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func sub(x, y int64) int64 {
	res := (x - y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func mul(x, y int64) int64 {
	res := (x * y) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func div(x, y int64) int64 {
	res := x * pow(y, mod-2) % mod
	if res < 0 {
		res += mod
	}
	return res
}

func pow(x, y int64) int64 {
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

func ns() string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func ni() int {
	line, _ := reader.ReadString('\n')
	i, _ := strconv.Atoi(strings.TrimSpace(line))
	return i
}

func nl() int64 {
	line, _ := reader.ReadString('\n')
	i, _ := strconv.ParseInt(strings.TrimSpace(line), 10, 64)
	return i
}

// End of Code
