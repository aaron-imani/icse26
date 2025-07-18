package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"sort"
	"math"
)

type Main struct {
	sc *bufio.Scanner
}

func (m *Main) solve() {
	m.sc.Scan()
	a, _ := strconv.Atoi(m.sc.Text())
	m.sc.Scan()
	b, _ := strconv.Atoi(m.sc.Text())

	fmt.Println(max(0, a-2*b))
}

func (m *Main) ni() int {
	m.sc.Scan()
	a, _ := strconv.Atoi(m.sc.Text())
	return a
}

func (m *Main) nl() int64 {
	m.sc.Scan()
	a, _ := strconv.ParseInt(m.sc.Text(), 10, 64)
	return a
}

func (m *Main) nf() float32 {
	m.sc.Scan()
	a, _ := strconv.ParseFloat(m.sc.Text(), 32)
	return float32(a)
}

func (m *Main) nd() float64 {
	m.sc.Scan()
	a, _ := strconv.ParseFloat(m.sc.Text(), 64)
	return a
}

func (m *Main) ns() string {
	m.sc.Scan()
	return m.sc.Text()
}

func (m *Main) nst(s string) []string {
	return strings.Split(s, " ")
}

func (m *Main) ia(a []int) {
	for i := 0; i < len(a); i++ {
		a[i] = m.ni()
	}
}

func (m *Main) la(a []int64) {
	for i := 0; i < len(a); i++ {
		a[i] = m.nl()
	}
}

func (m *Main) fa(a []float32) {
	for i := 0; i < len(a); i++ {
		a[i] = m.nf()
	}
}

func (m *Main) da(a []float64) {
	for i := 0; i < len(a); i++ {
		a[i] = m.nd()
	}
}

func (m *Main) sa(a []string, empty bool) {
	if empty {
		for i := 0; i < len(a); i++ {
			a[i] = ""
		}
	} else {
		for i := 0; i < len(a); i++ {
			a[i] = m.ns()
		}
	}
}

func (m *Main) ida(a [][]int, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = m.ni()
		}
	}
}

func (m *Main) lda(a [][]int64, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = m.nl()
		}
	}
}

func (m *Main) dda(a [][]float64, n, m int) {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			a[i][j] = m.nd()
		}
	}
}

func (m *Main) stoi(s string) int {
	a, _ := strconv.Atoi(s)
	return a
}

func (m *Main) stod(s string) float64 {
	a, _ := strconv.ParseFloat(s, 64)
	return a
}

func (m *Main) lmin(a []int64) int64 {
	min := int64(^uint64(0) >> 1)
	for i := 0; i < len(a); i++ {
		if min > a[i] {
			min = a[i]
		}
	}
	return min
}

func (m *Main) imin(a []int) int {
	min := int(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if min > a[i] {
			min = a[i]
		}
	}
	return min
}

func (m *Main) lmax(a []int64) int64 {
	max := int64(^uint64(0) >> 1)
	for i := 0; i < len(a); i++ {
		if max < a[i] {
			max = a[i]
		}
	}
	return max
}

func (m *Main) imax(a []int) int {
	max := int(^uint(0) >> 1)
	for i := 0; i < len(a); i++ {
		if max < a[i] {
			max = a[i]
		}
	}
	return max
}

func (m *Main) ibs(a []int, toFind int) bool {
	sort.Ints(a)
	min := 0
	max := len(a) - 1
	found := false

	for min <= max && !found {
		mid := min + (max-min)/2
		if a[mid] == toFind {
			found = true
		} else if toFind > a[mid] {
			min = mid + 1
		} else {
			max = mid - 1
		}
	}
	return found
}

func (m *Main) lbs(a []int64, toFind int64) bool {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	min := 0
	max := len(a) - 1
	found := false

	for min <= max && !found {
		mid := min + (max-min)/2
		if a[mid] == toFind {
			found = true
		} else if toFind > a[mid] {
			min = mid + 1
		} else {
			max = mid - 1
		}
	}
	return found
}

func (m *Main) stb(s string) int {
	sum := 0
	k := 0
	for i := len(s) - 1; i >= 0; i-- {
		sum += m.stoi(string(s[i])) * int(math.Pow(2, float64(k)))
		k++
	}
	return sum
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	m := Main{sc: sc}
	m.solve()
}
// End of Code
