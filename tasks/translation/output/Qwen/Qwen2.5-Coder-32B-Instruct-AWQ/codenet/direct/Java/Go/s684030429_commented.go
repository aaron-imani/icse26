package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	sc  *bufio.Scanner
	max int
	cur int
}

func (m *Main) solve() {
	a := m.ni()
	b := m.ni()

	fmt.Println(max(0, a-2*b))
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func (m *Main) ni() int {
	m.sc.Scan()
	num, _ := strconv.Atoi(m.sc.Text())
	return num
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	m := Main{sc: sc}
	m.solve()
}

// End of Code
