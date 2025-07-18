package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve() {
	tmp := ns()
	s := strings.Split(tmp, "")
	n := len(s)
	ans := 0
	cnt := 0
	for i := 0; i < n; i++ {
		if s[i] == "S" {
			cnt++
		} else {
			if cnt == 0 {
				continue
			}
			ans++
			cnt--
		}
	}
	out.Println(n - 2*ans)
}

const (
	mod  = 1000000007
	inf  = int(^uint(0) >> 1)
	linf = int64(^uint64(0) >> 1)
	dinf = 1e18
	eps  = 1e-10
	pi   = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
)

var (
	sb = strings.Builder{}
	is *bufio.Reader
	out *bufio.Writer
)

func reverseInt(ar []int) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverseInt64(ar []int64) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverseFloat64(ar []float64) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverseString(ar []string) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func getReverseString(s string) string {
	c := strings.Split(s, "")
	reverseString(c)
	return strings.Join(c, "")
}

func reverseInterface(ls []interface{}) {
	sz := len(ls)
	for i := 0; i < sz/2; i++ {
		t := ls[i]
		ls[i] = ls[sz-1-i]
		ls[sz-1-i] = t
	}
}

func sbnl() {
	sb.WriteString("\n")
}

func lowerBoundInt(a []int, x int) int {
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

func upperBoundInt(a []int, x int) int {
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

func rlowerBoundInt(a []int, x int) int {
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

func rupperBoundInt(a []int, x int) int {
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

func lowerBoundInt64(a []int64, x int64) int {
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

func upperBoundInt64(a []int64, x int64) int {
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

func rlowerBoundInt64(a []int64, x int64) int {
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

func rupperBoundInt64(a []int64, x int64) int {
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

func lowerBoundFloat64(a []float64, x float64) int {
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

func upperBoundFloat64(a []float64, x float64) int {
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

func rlowerBoundFloat64(a []float64, x float64) int {
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

func rupperBoundFloat64(a []float64, x float64) int {
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

func lowerBoundString(a []string, x string) int {
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

func upperBoundString(a []string, x string) int {
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

func rlowerBoundString(a []string, x string) int {
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

func rupperBoundString(a []string, x string) int {
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

func lowerBoundInterface(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
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
		fmt.Fprintf(os.Stderr, "%s:数値でないリストを二分探索しています。\n", "lowerBoundInterface")
		panic("runtime error")
	}
}

func upperBoundInterface(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
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
		fmt.Fprintf(os.Stderr, "%s:数値でないリストを二分探索しています。\n", "upperBoundInterface")
		panic("runtime error")
	}
}

func rupperBoundInterface(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
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
		fmt.Fprintf(os.Stderr, "%s:数値でないリストを二分探索しています。\n", "rupperBoundInterface")
		panic("runtime error")
	}
}

func rlowerBoundInterface(ls []interface{}, x interface{}) int {
	if len(ls) == 0 {
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
		fmt.Fprintf(os.Stderr, "%s:数値でないリストを二分探索しています。\n", "rlowerBoundInterface")
		panic("runtime error")
	}
}

func concatInt(x int, arr []int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concatIntEnd(arr []int, x int) []int {
	ret := make([]int, len(arr)+1)
	copy(ret, arr)
	ret[len(ret)-1] = x
	return ret
}

func concatInt64(x int64, arr []int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret[1:], arr)
	ret[0] = x
	return ret
}

func concatInt64End(arr []int64, x int64) []int64 {
	ret := make([]int64, len(arr)+1)
	copy(ret, arr)
	ret[len(ret)-1] = x
	return ret
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

func maxIntThree(x, y, z int) int {
	x = maxInt(x, y)
	x = maxInt(x, z)
	return x
}

func minIntThree(x, y, z int) int {
	x = minInt(x, y)
	x = minInt(x, z)
	return x
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

func maxInt64Three(x, y, z int64) int64 {
	x = maxInt64(x, y)
	x = maxInt64(x, z)
	return x
}

func minInt64Three(x, y, z int64) int64 {
	x = minInt64(x, y)
	x = minInt64(x, z)
	return x
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

func maxFloat64Three(x, y, z float64) float64 {
	x = maxFloat64(x, y)
	x = maxFloat64(x, z)
	return x
}

func minFloat64Three(x, y, z float64) float64 {
	x = minFloat64(x, y)
	x = minFloat64(x, z)
	return x
}

func sortInt(ar []int) {
	sort.Ints(ar)
}

func sortInt64(ar []int64) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
}

func sortFloat64(ar []float64) {
	sort.Float64s(ar)
}

func sortString(ar []string) {
	sort.Strings(ar)
}

func rsortInt(ar []int) {
	sort.Ints(ar)
	reverseInt(ar)
}

func rsortInt64(ar []int64) {
	sort.Slice(ar, func(i, j int) bool {
		return ar[i] < ar[j]
	})
	reverseInt64(ar)
}

func rsortFloat64(ar []float64) {
	sort.Float64s(ar)
	reverseFloat64(ar)
}

func rsortString(ar []string) {
	sort.Strings(ar)
	reverseString(ar)
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

func fillInt2D(arr [][]int, x int) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillInt642D(arr [][]int64, x int64) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillFloat642D(arr [][]float64, x float64) {
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = x
		}
	}
}

func fillBool2D(arr [][]bool, x bool) {
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
		return mul(x, pow(x, y-1))
	}
	root := pow(x, y/2)
	return mul(root, root)
}

func main() {
	is = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solve()
}

func readByte() byte {
	if len(inbuf) == 0 {
		inbuf = make([]byte, 1024)
		var n int
		var err error
		n, err = is.Read(inbuf)
		if n == 0 {
			panic(err)
		}
		buf = inbuf[:n]
	}
	b := buf[0]
	buf = buf[1:]
	return b
}

func isSpaceChar(c byte) bool {
	return !(c >= 33 && c <= 126)
}

func skip() byte {
	b := readByte()
	for isSpaceChar(b) {
		b = readByte()
	}
	return b
}

func ns() string {
	b := skip()
	var sb strings.Builder
	for !isSpaceChar(b) {
		sb.WriteByte(b)
		b = readByte()
	}
	return sb.String()
}

func nsInt(n int) []int {
	buf := make([]int, n)
	for i := 0; i < n; i++ {
		buf[i] = ni()
	}
	return buf
}

func nsInt64(n int) []int64 {
	buf := make([]int64, n)
	for i := 0; i < n; i++ {
		buf[i] = nl()
	}
	return buf
}

func ni() int {
	num := 0
	b := skip()
	minus := false
	if b == '-' {
		minus = true
		b = readByte()
	}
	for !(b >= '0' && b <= '9') {
		b = readByte()
	}
	for b >= '0' && b <= '9' {
		num = num*10 + int(b-'0')
		b = readByte()
	}
	if minus {
		return -num
	}
	return num
}

func nl() int64 {
	num := int64(0)
	b := skip()
	minus := false
	if b == '-' {
		minus = true
		b = readByte()
	}
	for !(b >= '0' && b <= '9') {
		b = readByte()
	}
	for b >= '0' && b <= '9' {
		num = num*10 + int64(b-'0')
		b = readByte()
	}
	if minus {
		return -num
	}
	return num
}

var buf []byte = make([]byte, 1024)

// End of Code
