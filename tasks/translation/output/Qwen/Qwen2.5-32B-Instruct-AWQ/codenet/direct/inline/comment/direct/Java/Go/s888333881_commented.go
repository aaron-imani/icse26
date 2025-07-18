package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Graph0n struct {
	dt []*Node0n
}

func NewGraph0n(sz int) *Graph0n {
	g := &Graph0n{make([]*Node0n, sz)}
	for i := range g.dt {
		g.dt[i] = &Node0n{}
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

func (g *Graph0n) GetAll(vn int) []int {
	return g.dt[vn].GetAll()
}

func (g *Graph0n) SizeOf(vn int) int {
	return g.dt[vn].Size()
}

func (g *Graph0n) Clear() {
	for i := range g.dt {
		g.dt[i].Clear()
	}
}

type Node0n struct {
	nextVs []int
}

func (n *Node0n) Add(val int) {
	n.nextVs = append(n.nextVs, val)
}

func (n *Node0n) Get(ad int) int {
	return n.nextVs[ad]
}

func (n *Node0n) GetAll() []int {
	return n.nextVs
}

func (n *Node0n) Size() int {
	return len(n.nextVs)
}

func (n *Node0n) Clear() {
	n.nextVs = nil
}

type Edge struct {
	from, v2 int
	weight   int64
}

type Edge2 struct {
	v2, cost1, cost2 int64
}

type ComparatorEdge struct{}

func (ComparatorEdge) Compare(a, b *Edge) int {
	if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return b.v2 - a.v2
	}
}

type V2Comp struct{}

func (V2Comp) Compare(a, b *Edge) int {
	if a.v2 > b.v2 {
		return -1
	} else if a.v2 < b.v2 {
		return 1
	} else if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return 0
	}
}

type antiV2 struct{}

func (antiV2) Compare(a, b *Edge) int {
	if a.v2 > b.v2 {
		return 1
	} else if a.v2 < b.v2 {
		return -1
	} else if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return 0
	}
}

type Vector struct {
	x, y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()

	s := scanner.Text()
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

const (
	INF  = 1e8
	INFL = 1e17
	E97  = 1e9 + 7
)

func abs(a int64) int64 {
	if a >= 0 {
		return a
	}
	return -a
}

func min(a, b int64) int64 {
	if a > b {
		return b
	}
	return a
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func pow(base, exp int64) int64 {
	ans := 1
	for i := 0; i < int(exp); i++ {
		ans *= base
	}
	return ans
}

func pow10E97(base, exp, p int64) int64 {
	if base == 0 {
		return 0
	}
	if exp == 0 {
		return 1
	}
	if exp == 2 {
		return (base * base) % p
	}

	d := getDigit2(exp)
	obPow2Pow := make([]int64, d)

	obPow2Pow[0] = base
	for i := 1; i < d; i++ {
		obPow2Pow[i] = (obPow2Pow[i-1] * obPow2Pow[i-1]) % p
	}

	ans := 1
	for i := d - 1; i >= 0; i-- {
		if exp >= (1 << uint(i)) {
			exp -= (1 << uint(i))
			ans = (ans * obPow2Pow[i]) % p
		}
	}
	return ans % p
}

func getDigit2(num int64) int {
	cf := 1
	d := 0
	for num >= cf {
		d++
		cf = (1 << uint(d))
	}
	return d
}

func isFlaged(bit int64, pos int) bool {
	return (bit & (1 << uint(pos))) > 0
}

func countFlaged(bit int64) int {
	ans := 0
	for i := 0; i < getDigit2(bit); i++ {
		if isFlaged(bit, i) {
			ans++
		}
	}
	return ans
}

// End of Code
