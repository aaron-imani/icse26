package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

const MOD2 = 998244353
var inv9 int64
var tenmod []int64

func modPow(x int64, y int64) int64 {
	res := int64(1)
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % MOD2
		}
		x = (x * x) % MOD2
		y /= 2
	}
	return res
}

type S struct {
	sum int64
	l   int
	r   int
}

func (s1 S) op(s2 S) S {
	sum := s1.sum + s2.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	l := math.Min(float64(s1.l), float64(s2.l))
	r := math.Max(float64(s1.r), float64(s2.r))
	return S{sum: sum, l: int(l), r: int(r)}
}

type F struct {
	D int64
	N int
}

func composite(f F, g F) F {
	return f
}

func mapF(f F, s S) S {
	N := f.N
	powL := N - s.l
	powR := N - s.r - 1
	term1 := tenmod[powL]
	term2 := tenmod[powR]
	c := term1 - term2
	if c < 0 {
		c += MOD2
	}
	sum := (f.D * c) % MOD2
	sum = (sum * inv9) % MOD2
	return S{sum: sum, l: s.l, r: s.r}
}

type LazySegTree struct {
	size int
	log  int
	dat  []S
	laz  []F
	e    S
	id   F
}

func NewLazySegTree(data []S) *LazySegTree {
	n := len(data)
	size := 1
	for size < n {
		size <<= 1
	}
	log := 0
	for (1 << log) < size {
		log++
	}
	lst := &LazySegTree{
		size: size,
		log:  log,
		dat:  make([]S, 2*size),
		laz:  make([]F, size),
		e:    S{sum: 0, l: math.MaxInt32, r: math.MinInt32},
		id:   F{D: 0, N: 0},
	}
	for i := 0; i < n; i++ {
		lst.dat[size+i] = data[i]
	}
	for i := n; i < size; i++ {
		lst.dat[size+i] = lst.e
	}
	for i := size - 1; i >= 1; i-- {
		lst.dat[i] = lst.dat[2*i].op(lst.dat[2*i+1])
	}
	return lst
}

func (lst *LazySegTree) push(k int) {
	if lst.laz[k] == lst.id {
		return
	}
	left := 2 * k
	right := left + 1
	lst.dat[left] = mapF(lst.laz[k], lst.dat[left])
	lst.dat[right] = mapF(lst.laz[k], lst.dat[right])
	if left < lst.size {
		lst.laz[left] = composite(lst.laz[k], lst.laz[left])
	}
	if right < lst.size {
		lst.laz[right] = composite(lst.laz[k], lst.laz[right])
	}
	lst.laz[k] = lst.id
}

func (lst *LazySegTree) pushTo(a, b int) {
	for i := lst.log; i > 0; i-- {
		if (a >> i) << i != a {
			lst.push(a >> i)
		}
		if (b >> i) << i != b {
			lst.push((b - 1) >> i)
		}
	}
}

func (lst *LazySegTree) updateFrom(a, b int) {
	for i := 1; i <= lst.log; i++ {
		if (a >> i) << i != a {
			node := a >> i
			lst.dat[node] = lst.dat[2*node].op(lst.dat[2*node+1])
		}
		if (b >> i) << i != b {
			node := (b - 1) >> i
			lst.dat[node] = lst.dat[2*node].op(lst.dat[2*node+1])
		}
	}
}

func (lst *LazySegTree) Apply(lOrig, rOrig int, f F) {
	if lOrig > rOrig {
		return
	}
	if lOrig == rOrig {
		return
	}
	lNode := lOrig + lst.size
	rNode := rOrig + lst.size
	lst.pushTo(lNode, rNode)
	for lNode < rNode {
		if (lNode & 1) == 1 {
			lst.dat[lNode] = mapF(f, lst.dat[lNode])
			if lNode < lst.size {
				lst.laz[lNode] = composite(f, lst.laz[lNode])
			}
			lNode++
		}
		if (rNode & 1) == 1 {
			rNode--
			lst.dat[rNode] = mapF(f, lst.dat[rNode])
			if rNode < lst.size {
				lst.laz[rNode] = composite(f, lst.laz[rNode])
			}
		}
		lNode >>= 1
		rNode >>= 1
	}
	lst.updateFrom(lOrig+lst.size, rOrig+lst.size)
}

func (lst *LazySegTree) AllProd() S {
	return lst.dat[1]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N, Q int
	fmt.Fscanf(reader, "%d %d", &N, &Q)

	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	inv9 = modPow(9, MOD2-2)

	data := make([]S, N)
	for i := 0; i < N; i++ {
		powIndex := N - i - 1
		data[i] = S{sum: tenmod[powIndex], l: i, r: i}
	}
	lst := NewLazySegTree(data)

	for q := 0; q < Q; q++ {
		var l, r int
		var D int64
		fmt.Fscanf(reader, "%d %d %d", &l, &r, &D)
		l--
		r--
		f := F{D: D, N: N}
		lst.Apply(l, r+1, f)
		fmt.Println(lst.AllProd().sum)
	}
}
// End of Code
