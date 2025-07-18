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

const mod = 1e9 + 7
var dx = []int{-1, 0, 1, 0}
var dy = []int{0, -1, 0, 1}
var dx8 = []int{-1, -1, -1, 0, 0, 1, 1, 1}
var dy8 = []int{-1, 0, 1, -1, 1, -1, 0, 1}
const inf = int(^uint(0) >> 1) / 2
const linf = int64(^uint64(0) >> 1) / 3
const dinf = float64(^uint64(0) >> 1) / 3
const eps = 1e-10
const pi = 3.14159265358979323846

var sb strings.Builder
var is = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func reverse(ar []int) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverse(ar []int64) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverse(ar []float64) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func reverse(ar []rune) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func getReverse(s string) string {
	c := []rune(s)
	reverse(c)
	s = string(c)
	return s
}

func reverse(ls []interface{}) {
	sz := len(ls)
	for i := 0; i < sz/2; i++ {
		t := ls[i]
		ls[i] = ls[sz-1-i]
		ls[sz-1-i] = t
	}
}

func reverse(ar []interface{}) {
	len := len(ar)
	for i := 0; i < len/2; i++ {
		t := ar[i]
		ar[i] = ar[len-1-i]
		ar[len-1-i] = t
	}
}

func sbnl() {
	sb.WriteString("\n")
}

func lowerBound(a []int, x int) int {
	l := -1
	r := len(a)
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

func main() {
	solve()
	out.Flush()
}

func ns() string {
	var s string
	fmt.Fscan(is, &s)
	return s
}

func ni() int {
	var i int
	fmt.Fscan(is, &i)
	return i
}

func nl() int64 {
	var l int64
	fmt.Fscan(is, &l)
	return l
}

// End of Code
