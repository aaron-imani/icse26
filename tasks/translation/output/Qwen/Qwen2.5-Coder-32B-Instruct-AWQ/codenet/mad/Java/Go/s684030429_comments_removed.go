package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	sc *bufio.Scanner
}

func (m *Main) solve() {
	a := m.ni()
	b := m.ni()

	fmt.Println(max(0, a-2*b))
}

func (m *Main) ni() int {
	m.sc.Scan()
	num, _ := strconv.Atoi(m.sc.Text())
	return num
}

func (m *Main) ns() string {
	m.sc.Scan()
	return m.sc.Text()
}

func (m *Main) nst(s string) []string {
	return strings.Split(s, " ")
}

func (m *Main) stoi(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

func (m *Main) stod(s string) float64 {
	num, _ := strconv.ParseFloat(s, 64)
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	m := Main{sc: sc}
	m.solve()
}

// End of Code
