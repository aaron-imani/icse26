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
	pi   = 3.14159265358979323846
)

var (
	sb = strings.Builder{}
	is *bufio.Reader
)

func main() {
	is = bufio.NewReader(os.Stdin)
	solve()
}

func ns() string {
	var b []byte
	for {
		l, p, err := is.ReadLine()
		if err != nil {
			panic(err)
		}
		b = append(b, l...)
		if !p {
			break
		}
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

// End of Code
