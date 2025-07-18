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

func (ce *ComparatorEdge) Compare(a, b *Edge) int {
	if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return b.v2 - a.v2
	}
}

type V2Comp struct{}

func (vc *V2Comp) Compare(a, b *Edge) int {
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

type AntiV2 struct{}

func (av *AntiV2) Compare(a, b *Edge) int {
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

const (
	INF  = 100000000
	INFL = 1000000000000000000
	E97  = 1000000007
)

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func absL(a int64) int64 {
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

func minL(a, b int64) int64 {
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

func maxL(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func pow(base, exp int) int {
	result := 1
	for i := 0; i < exp; i++ {
		result *= base
	}
	return result
}

func powL(base, exp int64) int64 {
	result := int64(1)
	for i := int64(0); i < exp; i++ {
		result *= base
	}
	return result
}

func powMod(base, exp, mod int64) int64 {
	result := int64(1)
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		base = (base * base) % mod
		exp /= 2
	}
	return result
}

func countSetBits(n int64) int {
	count := 0
	for n > 0 {
		count += int(n & 1)
		n >>= 1
	}
	return count
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n int
	fmt.Scanf("%d", &n)
	s := scanner.Text()

	flaged := make([]bool, n)
	pop1st := int64(0)
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
			pop1st++
		}
	}

	surp1 := int64(0)
	for i := 0; i < n; i++ {
		surp1 *= 2
		if flaged[i] {
			surp1++
		}
		surp1 %= (pop1st + 1)
	}

	surp9 := int64(0)
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
			dif := powMod(2, n-p-1, pop1st-1)
			dw -= dif
			dw += (pop1st - 1)
			dw %= (pop1st - 1)

			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countSetBits(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		} else {
			dw := surp1
			dif := powMod(2, n-p-1, pop1st+1)
			dw += dif
			dw %= (pop1st + 1)

			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Println(1 / 0)
				}
				count := countSetBits(dw)
				dw %= int64(count)
				ans++
			}
			fmt.Println(ans)
		}
	}
}
// End of Code
