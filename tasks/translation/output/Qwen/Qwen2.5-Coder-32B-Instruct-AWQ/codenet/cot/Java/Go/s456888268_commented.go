package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	mod  = 1000000007
	inf  = 1<<31 - 1
	linf = 1<<63 - 1
	dinf = 1e18
	eps  = 1e-10
	pi   = 3.14159265358979323846
)

var (
	sb    strings.Builder
	is    *bufio.Reader
	out   *bufio.Writer
	input string
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
	out.WriteString(fmt.Sprintf("%d\n", n-2*ans))
}

func main() {
	input = ""
	is = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	if len(input) > 0 {
		is = bufio.NewReader(strings.NewReader(input))
	}
	solve()
	out.Flush()
}

func ns() string {
	b := make([]byte, 0)
	for {
		c := readByte()
		if c == '\n' || c == ' ' || c == '\t' || c == -1 {
			break
		}
		b = append(b, c)
	}
	return string(b)
}

func ni() int {
	i, _ := strconv.Atoi(ns())
	return i
}

func nl() int64 {
	l, _ := strconv.ParseInt(ns(), 10, 64)
	return l
}

func readByte() byte {
	if len(input) == 0 {
		b, _ := is.ReadByte()
		return b
	}
	b := input[0]
	input = input[1:]
	return b
}

func reverseInts(ar []int) {
	for i, j := 0, len(ar)-1; i < j; i, j = i+1, j-1 {
		ar[i], ar[j] = ar[j], ar[i]
	}
}

func reverseInt64s(ar []int64) {
	for i, j := 0, len(ar)-1; i < j; i, j = i+1, j-1 {
		ar[i], ar[j] = ar[j], ar[i]
	}
}

func reverseFloat64s(ar []float64) {
	for i, j := 0, len(ar)-1; i < j; i, j = i+1, j-1 {
		ar[i], ar[j] = ar[j], ar[i]
	}
}

func reverseRunes(ar []rune) {
	for i, j := 0, len(ar)-1; i < j; i, j = i+1, j-1 {
		ar[i], ar[j] = ar[j], ar[i]
	}
}

func reverseStrings(ar []string) {
	for i, j := 0, len(ar)-1; i < j; i, j = i+1, j-1 {
		ar[i], ar[j] = ar[j], ar[i]
	}
}

func getReverse(s string) string {
	c := []rune(s)
	reverseRunes(c)
	return string(c)
}

func lowerBoundInts(a []int, x int) int {
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

func upperBoundInts(a []int, x int) int {
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

func rlowerBoundInts(a []int, x int) int {
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

func rupperBoundInts(a []int, x int) int {
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

func lowerBoundInt64s(a []int64, x int64) int {
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

func upperBoundInt64s(a []int64, x int64) int {
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

func rlowerBoundInt64s(a []int64, x int64) int {
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

func rupperBoundInt64s(a []int64, x int64) int {
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

func lowerBoundFloat64s(a []float64, x float64) int {
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

func upperBoundFloat64s(a []float64, x float64) int {
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

func rlowerBoundFloat64s(a []float64, x float64) int {
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

func rupperBoundFloat64s(a []float64, x float64) int {
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

func lowerBoundRunes(a []rune, x rune) int {
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

func upperBoundRunes(a []rune, x rune) int {
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

func rlowerBoundRunes(a []rune, x rune) int {
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

func rupperBoundRunes(a []rune, x rune) int {
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

func maxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minInt(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func maxInt3(x, y, z int) int {
	return maxInt(maxInt(x, y), z)
}

func minInt3(x, y, z int) int {
	return minInt(minInt(x, y), z)
}

func maxInt64(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func minInt64(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func maxInt643(x, y, z int64) int64 {
	return maxInt64(maxInt64(x, y), z)
}

func minInt643(x, y, z int64) int64 {
	return minInt64(minInt64(x, y), z)
}

func maxFloat64(x, y float64) float64 {
	if x > y {
		return x
	}
	return y
}

func minFloat64(x, y float64) float64 {
	if x < y {
		return x
	}
	return y
}

func maxFloat643(x, y, z float64) float64 {
	return maxFloat64(maxFloat64(x, y), z)
}

func minFloat643(x, y, z float64) float64 {
	return minFloat64(minFloat64(x, y), z)
}

func sortInts(ar []int) {
	quickSortInts(ar, 0, len(ar)-1)
}

func quickSortInts(ar []int, left, right int) {
	if left >= right {
		return
	}
	pivot := ar[(left+right)/2]
	i, j := left, right
	for i <= j {
		for ar[i] < pivot {
			i++
		}
		for ar[j] > pivot {
			j--
		}
		if i <= j {
			ar[i], ar[j] = ar[j], ar[i]
			i++
			j--
		}
	}
	quickSortInts(ar, left, j)
	quickSortInts(ar, i, right)
}

func sortInt64s(ar []int64) {
	quickSortInt64s(ar, 0, len(ar)-1)
}

func quickSortInt64s(ar []int64, left, right int) {
	if left >= right {
		return
	}
	pivot := ar[(left+right)/2]
	i, j := left, right
	for i <= j {
		for ar[i] < pivot {
			i++
		}
		for ar[j] > pivot {
			j--
		}
		if i <= j {
			ar[i], ar[j] = ar[j], ar[i]
			i++
			j--
		}
	}
	quickSortInt64s(ar, left, j)
	quickSortInt64s(ar, i, right)
}

func sortFloat64s(ar []float64) {
	quickSortFloat64s(ar, 0, len(ar)-1)
}

func quickSortFloat64s(ar []float64, left, right int) {
	if left >= right {
		return
	}
	pivot := ar[(left+right)/2]
	i, j := left, right
	for i <= j {
		for ar[i] < pivot {
			i++
		}
		for ar[j] > pivot {
			j--
		}
		if i <= j {
			ar[i], ar[j] = ar[j], ar[i]
			i++
			j--
		}
	}
	quickSortFloat64s(ar, left, j)
	quickSortFloat64s(ar, i, right)
}

func sortRunes(ar []rune) {
	quickSortRunes(ar, 0, len(ar)-1)
}

func quickSortRunes(ar []rune, left, right int) {
	if left >= right {
		return
	}
	pivot := ar[(left+right)/2]
	i, j := left, right
	for i <= j {
		for ar[i] < pivot {
			i++
		}
		for ar[j] > pivot {
			j--
		}
		if i <= j {
			ar[i], ar[j] = ar[j], ar[i]
			i++
			j--
		}
	}
	quickSortRunes(ar, left, j)
	quickSortRunes(ar, i, right)
}

func rsortInts(ar []int) {
	sortInts(ar)
	reverseInts(ar)
}

func rsortInt64s(ar []int64) {
	sortInt64s(ar)
	reverseInt64s(ar)
}

func rsortFloat64s(ar []float64) {
	sortFloat64s(ar)
	reverseFloat64s(ar)
}

func rsortRunes(ar []rune) {
	sortRunes(ar)
	reverseRunes(ar)
}

func fillInts(arr []int, x int) {
	for i := range arr {
		arr[i] = x
	}
}

func fillInt64s(arr []int64, x int64) {
	for i := range arr {
		arr[i] = x
	}
}

func fillBools(arr []bool, x bool) {
	for i := range arr {
		arr[i] = x
	}
}

func fillFloat64s(arr []float64, x float64) {
	for i := range arr {
		arr[i] = x
	}
}

func fillInts2D(arr [][]int, x int) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillInt64s2D(arr [][]int64, x int64) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillBools2D(arr [][]bool, x bool) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillFloat64s2D(arr [][]float64, x float64) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
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

// End of Code
