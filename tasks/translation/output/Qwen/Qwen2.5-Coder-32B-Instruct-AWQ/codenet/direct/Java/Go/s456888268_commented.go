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
	sb    strings.Builder
	is    *bufio.Reader
	out   *bufio.Writer
	INPUT = ""
)

func main() {
	is = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	solve()
	out.Flush()
}

func ns() string {
	b, _ := is.ReadBytes('\n')
	return strings.TrimSpace(string(b))
}

func ni() int {
	i, _ := strconv.Atoi(ns())
	return i
}

func nl() int64 {
	l, _ := strconv.ParseInt(ns(), 10, 64)
	return l
}

// End of Code
