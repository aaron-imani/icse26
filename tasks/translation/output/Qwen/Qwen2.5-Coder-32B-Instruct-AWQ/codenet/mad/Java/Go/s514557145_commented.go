package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"math/bits"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var (
	tenmod []int64
	inv9   int64
)

type S struct {
	sum int64
	l   int
	r   int
}

type F struct {
	D int64
	N int
}

func (s S) op(s2 S) S {
	sum := s.sum + s2.sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	return S{sum, min(s.l, s2.l), max(s.r, s2.r)}
}

func (f F) mapFunc(s S) S {
	c := (tenmod[f.N-s.l] - tenmod[f.N-s.r-1])
	if c < 0 {
		c += MOD2
	}
	return S{(f.D * c % MOD2 * inv9) % MOD2, s.l, s.r}
}

func (f F) composite(f2 F) F {
	return F{f.D, f.N}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func modInv(x int64) int64 {
	return modPow(x, MOD2-2)
}

func modPow(x, y int64) int64 {
	z := int64(1)
	for y > 0 {
		if y%2 == 0 {
			x = (x * x) % MOD2
			y /= 2
		} else {
			z = (z * x) % MOD2
			y--
		}
	}
	return z
}

type LazySegTree struct {
	MAX         int
	N           int
	Log         int
	Op          func(S, S) S
	E           S
	Mapping     func(F, S) S
	Composition func(F, F) F
	Id          F
	Dat         []S
	Laz         []F
}

func NewLazySegTree(n int, op func(S, S) S, e S, mapping func(F, S) S, composition func(F, F) F, id F) *LazySegTree {
	k := 1
	for k < n {
		k <<= 1
	}
	lst := &LazySegTree{
		MAX:         n,
		N:           k,
		Log:         bits.Len(uint(k)) - 1,
		Op:          op,
		E:           e,
		Mapping:     mapping,
		Composition: composition,
		Id:          id,
		Dat:         make([]S, k*2),
		Laz:         make([]F, k),
	}
	for i := range lst.Dat {
		lst.Dat[i] = e
	}
	for i := range lst.Laz {
		lst.Laz[i] = id
	}
	return lst
}

func (lst *LazySegTree) build(dat []S) {
	l := len(dat)
	copy(lst.Dat[lst.N:lst.N+l], dat)
	for i := lst.N - 1; i > 0; i-- {
		lst.Dat[i] = lst.Op(lst.Dat[i<<1|0], lst.Dat[i<<1|1])
	}
}

func (lst *LazySegTree) push(k int) {
	if lst.Laz[k] == lst.Id {
		return
	}
	lk := k<<1 | 0
	rk := k<<1 | 1
	lst.Dat[lk] = lst.Mapping(lst.Laz[k], lst.Dat[lk])
	lst.Dat[rk] = lst.Mapping(lst.Laz[k], lst.Dat[rk])
	if lk < lst.N {
		lst.Laz[lk] = lst.Composition(lst.Laz[k], lst.Laz[lk])
	}
	if rk < lst.N {
		lst.Laz[rk] = lst.Composition(lst.Laz[k], lst.Laz[rk])
	}
	lst.Laz[k] = lst.Id
}

func (lst *LazySegTree) pushTo(k int) {
	for i := lst.Log; i > 0; i-- {
		lst.push(k >> i)
	}
}

func (lst *LazySegTree) pushTo(lk, rk int) {
	for i := lst.Log; i > 0; i-- {
		if (lk>>i)<<i != lk {
			lst.push(lk >> i)
		}
		if (rk>>i)<<i != rk {
			lst.push(rk >> i)
		}
	}
}

func (lst *LazySegTree) updateFrom(k int) {
	k >>= 1
	for k > 0 {
		lst.Dat[k] = lst.Op(lst.Dat[k<<1|0], lst.Dat[k<<1|1])
		k >>= 1
	}
}

func (lst *LazySegTree) updateFrom(lk, rk int) {
	for i := 1; i <= lst.Log; i++ {
		if (lk>>i)<<i != lk {
			lki := lk >> i
			lst.Dat[lki] = lst.Op(lst.Dat[lki<<1|0], lst.Dat[lki<<1|1])
		}
		if (rk>>i)<<i != rk {
			rki := (rk - 1) >> i
			lst.Dat[rki] = lst.Op(lst.Dat[rki<<1|0], lst.Dat[rki<<1|1])
		}
	}
}

func (lst *LazySegTree) set(p int, x S) {
	if p < 0 || p >= lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d).", p, 0, lst.MAX))
	}
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = x
	lst.updateFrom(p)
}

func (lst *LazySegTree) get(p int) S {
	if p < 0 || p >= lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d).", p, 0, lst.MAX))
	}
	p += lst.N
	lst.pushTo(p)
	return lst.Dat[p]
}

func (lst *LazySegTree) allProd() S {
	return lst.Dat[1]
}

func (lst *LazySegTree) apply(p int, f F) {
	if p < 0 || p >= lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d).", p, 0, lst.MAX))
	}
	p += lst.N
	lst.pushTo(p)
	lst.Dat[p] = lst.Mapping(f, lst.Dat[p])
	lst.updateFrom(p)
}

func (lst *LazySegTree) applyRange(l, r int, f F) {
	if l > r {
		panic(fmt.Sprintf("Invalid range: [%d, %d)", l, r))
	}
	if l < 0 || l > lst.MAX || r < 0 || r > lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d].", l, 0, lst.MAX))
	}
	if l == r {
		return
	}
	l += lst.N
	r += lst.N
	lst.pushTo(l, r)
	for l2, r2 := l, r; l2 < r2; {
		if l2&1 == 1 {
			lst.Dat[l2] = lst.Mapping(f, lst.Dat[l2])
			if l2 < lst.N {
				lst.Laz[l2] = lst.Composition(f, lst.Laz[l2])
			}
			l2++
		}
		if r2&1 == 1 {
			r2--
			lst.Dat[r2] = lst.Mapping(f, lst.Dat[r2])
			if r2 < lst.N {
				lst.Laz[r2] = lst.Composition(f, lst.Laz[r2])
			}
		}
		l2 >>= 1
		r2 >>= 1
	}
	lst.updateFrom(l, r)
}

func (lst *LazySegTree) maxRight(l int, g func(S) bool) int {
	if l < 0 || l > lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d].", l, 0, lst.MAX))
	}
	if !g(lst.E) {
		panic("Identity element must satisfy the condition.")
	}
	if l == lst.MAX {
		return lst.MAX
	}
	l += lst.N
	lst.pushTo(l)
	sum := lst.E
	for {
		l >>= bits.TrailingZeros(uint(l))
		if !g(lst.Op(sum, lst.Dat[l])) {
			for l < lst.N {
				lst.push(l)
				l = l << 1
				if g(lst.Op(sum, lst.Dat[l])) {
					sum = lst.Op(sum, lst.Dat[l])
					l++
				}
			}
			return l - lst.N
		}
		sum = lst.Op(sum, lst.Dat[l])
		l++
		if (l & -l) == l {
			break
		}
	}
	return lst.MAX
}

func (lst *LazySegTree) minLeft(r int, g func(S) bool) int {
	if r < 0 || r > lst.MAX {
		panic(fmt.Sprintf("Index %d is not in [%d, %d].", r, 0, lst.MAX))
	}
	if !g(lst.E) {
		panic("Identity element must satisfy the condition.")
	}
	if r == 0 {
		return 0
	}
	r += lst.N
	lst.pushTo(r - 1)
	sum := lst.E
	for {
		r--
		for r > 1 && (r&1) == 1 {
			r >>= 1
		}
		if !g(lst.Op(lst.Dat[r], sum)) {
			for r < lst.N {
				lst.push(r)
				r = r<<1 | 1
				if g(lst.Op(lst.Dat[r], sum)) {
					sum = lst.Op(lst.Dat[r], sum)
					r--
				}
			}
			return r + 1 - lst.N
		}
		sum = lst.Op(lst.Dat[r], sum)
		if (r & -r) == r {
			break
		}
	}
	return 0
}

type InputReader struct {
	in    *bufio.Reader
	buf   []byte
	index int
}

func NewInputReader(r *bufio.Reader) *InputReader {
	return &InputReader{r, make([]byte, 1024), 0}
}

func (ir *InputReader) hasNextByte() bool {
	if ir.index < len(ir.buf) {
		return true
	}
	_, err := ir.in.Read(ir.buf)
	if err != nil {
		return false
	}
	ir.index = 0
	return len(ir.buf) > 0
}

func (ir *InputReader) readByte() byte {
	if !ir.hasNextByte() {
		return 0
	}
	b := ir.buf[ir.index]
	ir.index++
	return b
}

func (ir *InputReader) isSpaceChar(c byte) bool {
	return !(c >= 33 && c <= 126)
}

func (ir *InputReader) skip() {
	for ir.hasNextByte() && ir.isSpaceChar(ir.readByte()) {
	}
}

func (ir *InputReader) hasNext() bool {
	ir.skip()
	return ir.hasNextByte()
}

func (ir *InputReader) next() string {
	if !ir.hasNext() {
		panic("No more input")
	}
	var sb strings.Builder
	b := ir.readByte()
	for !ir.isSpaceChar(b) {
		sb.WriteByte(b)
		b = ir.readByte()
	}
	return sb.String()
}

func (ir *InputReader) nextInt() int {
	if !ir.hasNext() {
		panic("No more input")
	}
	b := ir.readByte()
	for ir.isSpaceChar(b) {
		b = ir.readByte()
	}
	minus := false
	if b == '-' {
		minus = true
		b = ir.readByte()
	}
	var res int
	for !ir.isSpaceChar(b) {
		if b < '0' || b > '9' {
			panic("Invalid input")
		}
		res = res*10 + int(b-'0')
		b = ir.readByte()
	}
	if minus {
		res = -res
	}
	return res
}

func (ir *InputReader) nextLong() int64 {
	if !ir.hasNext() {
		panic("No more input")
	}
	b := ir.readByte()
	for ir.isSpaceChar(b) {
		b = ir.readByte()
	}
	minus := false
	if b == '-' {
		minus = true
		b = ir.readByte()
	}
	var res int64
	for !ir.isSpaceChar(b) {
		if b < '0' || b > '9' {
			panic("Invalid input")
		}
		res = res*10 + int64(b-'0')
		b = ir.readByte()
	}
	if minus {
		res = -res
	}
	return res
}

func (ir *InputReader) nextDouble() float64 {
	return parseFloat(ir.next())
}

func parseFloat(s string) float64 {
	f, err := strconv.ParseFloat(s, 64)
	if err != nil {
		panic("Invalid input")
	}
	return f
}

func (ir *InputReader) nextIntArray(n int) []int {
	a := make([]int, n)
	for i := range a {
		a[i] = ir.nextInt()
	}
	return a
}

func (ir *InputReader) nextLongArray(n int) []int64 {
	a := make([]int64, n)
	for i := range a {
		a[i] = ir.nextLong()
	}
	return a
}

func (ir *InputReader) nextCharMap(n, m int) [][]byte {
	mapData := make([][]byte, n)
	for i := range mapData {
		mapData[i] = []byte(ir.next())
	}
	return mapData
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	sc := NewInputReader(in)

	N := sc.nextInt()
	Q := sc.nextInt()
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for j := 1; j <= N; j++ {
		tenmod[j] = (tenmod[j-1] * 10) % MOD2
	}
	inv9 = modInv(9)

	dat := make([]S, N)
	for i := range dat {
		dat[i] = S{tenmod[N-i-1], i, i}
	}
	lazySegTree := NewLazySegTree(N, func(s1, s2 S) S { return s1.op(s2) }, S{0, 1<<31-1, -1<<31}, func(f F, s S) S { return f.mapFunc(s) }, func(f, f2 F) F { return f.composite(f2) }, F{0, 0})
	for j := 0; j < Q; j++ {
		l := sc.nextInt() - 1
		r := sc.nextInt() - 1
		D := sc.nextLong()
		lazySegTree.applyRange(l, r+1, F{D, N})
		fmt.Fprintln(out, lazySegTree.allProd().sum)
	}
}

// End of Code
