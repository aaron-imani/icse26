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
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
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
	fmt.Fprintln(writer, n-2*ans)
}

func main() {
	scanner.Split(bufio.ScanWords)
	solve()
	writer.Flush()
}

func ns() string {
	scanner.Scan()
	return scanner.Text()
}

func ni() int {
	scanner.Scan()
	i, _ := strconv.Atoi(scanner.Text())
	return i
}

func nl() int64 {
	scanner.Scan()
	i, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return i
}

func nf() float64 {
	scanner.Scan()
	i, _ := strconv.ParseFloat(scanner.Text(), 64)
	return i
}

func nss(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = ns()
	}
	return a
}

func nis(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = ni()
	}
	return a
}

func nils(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = nl()
	}
	return a
}

func nfs(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = nf()
	}
	return a
}

func reverseInts(a []int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseInt64s(a []int64) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseFloat64s(a []float64) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseStrings(a []string) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseRuneSlice(a []rune) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func getReverse(s string) string {
	c := []rune(s)
	reverseRuneSlice(c)
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

func lowerBoundStrings(a []string, x string) int {
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

func upperBoundStrings(a []string, x string) int {
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

func rlowerBoundStrings(a []string, x string) int {
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

func rupperBoundStrings(a []string, x string) int {
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

func sortInts(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortInt64s(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortFloat64s(a []float64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortStrings(a []string) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortRunes(a []rune) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func rsortInts(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func rsortInt64s(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func rsortFloat64s(a []float64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func rsortStrings(a []string) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func rsortRunes(a []rune) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

func fillInts(a []int, x int) {
	for i := range a {
		a[i] = x
	}
}

func fillInt64s(a []int64, x int64) {
	for i := range a {
		a[i] = x
	}
}

func fillBools(a []bool, x bool) {
	for i := range a {
		a[i] = x
	}
}

func fillFloat64s(a []float64, x float64) {
	for i := range a {
		a[i] = x
	}
}

func fillInts2D(a [][]int, x int) {
	for i := range a {
		for j := range a[i] {
			a[i][j] = x
		}
	}
}

func fillInt64s2D(a [][]int64, x int64) {
	for i := range a {
		for j := range a[i] {
			a[i][j] = x
		}
	}
}

func fillBools2D(a [][]bool, x bool) {
	for i := range a {
		for j := range a[i] {
			a[i][j] = x
		}
	}
}

func fillFloat64s2D(a [][]float64, x float64) {
	for i := range a {
		for j := range a[i] {
			a[i][j] = x
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
		return mul(x, pow(x, y-1))
	}
	root := pow(x, y/2)
	return mul(root, root)
}

// End of Code
