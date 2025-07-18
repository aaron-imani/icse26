package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

type Main struct {
	sc *bufio.Scanner
	max int
	cur int
}

func (m *Main) solve() {
	var a, b int
	fmt.Scan(&a, &b)

	fmt.Println(math.Max(0, float64(a-2*b)))
}

func NewMain() *Main {
	return &Main{
		sc: bufio.NewScanner(os.Stdin),
	}
}

func (m *Main) ni() int {
	m.sc.Scan()
	num, _ := strconv.Atoi(m.sc.Text())
	return num
}

func (m *Main) nl() int64 {
	m.sc.Scan()
	num, _ := strconv.ParseInt(m.sc.Text(), 10, 64)
	return num
}

func (m *Main) nf() float32 {
	m.sc.Scan()
	num, _ := strconv.ParseFloat(m.sc.Text(), 32)
	return float32(num)
}

func (m *Main) nd() float64 {
	m.sc.Scan()
	num, _ := strconv.ParseFloat(m.sc.Text(), 64)
	return num
}

func (m *Main) ns() string {
	m.sc.Scan()
	return m.sc.Text()
}

func (m *Main) ia(a []int) {
	for i := range a {
		a[i] = m.ni()
	}
}

func (m *Main) la(a []int64) {
	for i := range a {
		a[i] = m.nl()
	}
}

func (m *Main) fa(a []float32) {
	for i := range a {
		a[i] = m.nf()
	}
}

func (m *Main) da(a []float64) {
	for i := range a {
		a[i] = m.nd()
	}
}

func (m *Main) sa(a []string, empty bool) {
	if empty {
		for i := range a {
			a[i] = ""
		}
	} else {
		for i := range a {
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
		for j := _range m; j < m; j++ {
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
	num, _ := strconv.Atoi(s)
	return num
}

func (m *Main) stod(s string) float64 {
	num, _ := strconv.ParseFloat(s, 64)
	return num
}

func (m *Main) lmin(a []int64) int64 {
	min := math.MaxInt64
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func (m *Main) imin(a []int) int {
	min := math.MaxInt32
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func (m *Main) lmax(a []int64) int64 {
	max := math.MinInt64
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func (m *Main) imax(a []int) int {
	max := math.MinInt32
	for _, v := range a {
		if v > max {
			max = v
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
		num, _ := strconv.Atoi(string(s[i]))
		sum += num * int(math.Pow(2, float64(k)))
		k++
	}
	return sum
}

func main() {
	mainObj := NewMain()
	mainObj.sc.Split(bufio.ScanWords)
	mainObj.solve()
}
// End of Code
