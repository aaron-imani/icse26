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
	fmt.Println(n - 2*ans)
}

const (
	mod  = 1000000007
	inf  = 1<<31 - 1
	linf = 1<<63 - 1
	dinf = 1e18
	eps  = 1e-10
	pi   = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()
	solve()
}

func ns() string {
	in.Scan()
	return in.Text()
}

func ni() int {
	i, _ := strconv.Atoi(ns())
	return i
}

func nl() int64 {
	l, _ := strconv.ParseInt(ns(), 10, 64)
	return l
}

func nf() float64 {
	f, _ := strconv.ParseFloat(ns(), 64)
	return f
}

func nss() []string {
	return strings.Fields(ns())
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

// End of Code
