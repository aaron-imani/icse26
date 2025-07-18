package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Graph0n struct {
	dt []*Node0n
}

func NewGraph0n(sz int) *Graph0n {
	g := &Graph0n{dt: make([]*Node0n, sz)}
	for i := 0; i < sz; i++ {
		g.dt[i] = &Node0n{next_vs: make([]int, 0)}
	}
	return g
}

func (g *Graph0n) Add(vn, val int) {
	g.dt[vn].Add(val)
}

func (g *Graph0n) Add2(vn, val int) {
	g.dt[vn].Add(val)
	g.dt[val].Add(vn)
}

func (g *Graph0n) Get(vn, index int) int {
	return g.dt[vn].Get(index)
}

func (g *Graph0n) Get(vn int) []int {
	return g.dt[vn].GetAll()
}

func (g *Graph0n) SizeOf(vn int) int {
	return g.dt[vn].Size()
}

func (g *Graph0n) Clear() {
	for i := 0; i < len(g.dt); i++ {
		g.dt[i].Clear()
	}
}

type Node0n struct {
	next_vs []int
}

func (n *Node0n) Add(val int) {
	n.next_vs = append(n.next_vs, val)
}

func (n *Node0n) Get(ad int) int {
	return n.next_vs[ad]
}

func (n *Node0n) GetAll() []int {
	return n.next_vs
}

func (n *Node0n) Size() int {
	return len(n.next_vs)
}

func (n *Node0n) Clear() {
	n.next_vs = make([]int, 0)
}

type Edge struct {
	from   int
	v2     int
	weight int64
}

type Edge2 struct {
	v2    int
	cost1 int64
	cost2 int64
}

type Vector struct {
	x int
	y int
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	s := nextString(sc)
	flaged := make([]bool, n)
	pop1st := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	surp1 := 0
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1++
		}
		surp1 %= (pop1st + 1)
	}

	surp9 := 0
	if pop1st > 1 {
		for i := 0; i < n; i++ {
			surp9 *= 2
			if flaged[i] {
				surp9++
			}
			surp9 %= (pop1st - 1)
		}
	}

	for p := 0; p < n; p++ {
		if flaged[p] {
			if pop1st == 1 {
				fmt.Println(0)
				continue
			}
			dw := surp9
			dif := pow10E97(2, n-p-1, pop1st-1)
			dw -= dif
			dw += (pop1st - 1)
			dw %= (pop1st - 1)
			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countFlaged(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			dif := pow10E97(2, n-p-1, pop1st+1)
			dw += dif
			dw %= (pop1st + 1)
			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countFlaged(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		}
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

const (
	INF  = 100000000
	INFL = 1000000000000000000
	e97  = 1000000007
)

func abs(a int64) int64 {
	if a >= 0 {
		return a
	}
	return -a
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pow(n, k int) int {
	ans := 1
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow10E97(ob, soeji, p int64) int64 {
	if ob == 0 {
		return 0
	}
	if soeji == 0 {
		return 1
	}
	if soeji == 2 {
		return (ob * ob) % p
	}

	d := getDigit2(soeji)
	ob_pow_2pow := make([]int64, d)

	ob_pow_2pow[0] = ob
	for i := 1; i < d; i++ {
		ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p
	}

	ans := int64(1)
	for i := d - 1; i >= 0; i-- {
		if soeji >= (1 << i) {
			soeji -= (1 << i)
			ans = (ans * ob_pow_2pow[i]) % p
		}
	}
	return ans % p
}

func getDigit2(num int64) int {
	cf := int64(1)
	d := 0
	for num >= cf {
		d++
		cf = (1 << d)
	}
	return d
}

func countFlaged(bit int64) int {
	ans := 0
	for i := 0; i < getDigit2(bit); i++ {
		if (bit & (1 << i)) > 0 {
			ans++
		}
	}
	return ans
}

func fill(ob []bool, res bool) {
	for i := range ob {
		ob[i] = res
	}
}

func fillInt(ob []int, res int) {
	for i := range ob {
		ob[i] = res
	}
}

func fillLong(ob []int64, res int64) {
	for i := range ob {
		ob[i] = res
	}
}

func fillChar(ob []byte, res byte) {
	for i := range ob {
		ob[i] = res
	}
}

func fillDouble(ob []float64, res float64) {
	for i := range ob {
		ob[i] = res
	}
}

func fill2DBool(ob [][]bool, res bool) {
	for i := range ob {
		for j := range ob[i] {
			ob[i][j] = res
		}
	}
}

func fill2DInt(ob [][]int, res int) {
	for i := range ob {
		for j := range ob[i] {
			ob[i][j] = res
		}
	}
}

func fill2DLong(ob [][]int64, res int64) {
	for i := range ob {
		for j := range ob[i] {
			ob[i][j] = res
		}
	}
}

func fill2DChar(ob [][]byte, res byte) {
	for i := range ob {
		for j := range ob[i] {
			ob[i][j] = res
		}
	}
}

func fill2DDouble(ob [][]float64, res float64) {
	for i := range ob {
		for j := range ob[i] {
			ob[i][j] = res
		}
	}
}

func fill3DInt(ob [][][]int, res int) {
	for i := range ob {
		for j := range ob[i] {
			for k := range ob[i][j] {
				ob[i][j][k] = res
			}
		}
	}
}

func fill3DLong(ob [][][]int64, res int64) {
	for i := range ob {
		for j := range ob[i] {
			for k := range ob[i][j] {
				ob[i][j][k] = res
			}
		}
	}
}

// End of Code
