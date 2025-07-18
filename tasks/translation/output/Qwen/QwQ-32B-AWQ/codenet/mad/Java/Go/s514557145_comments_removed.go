package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

const (
	MOD1 = 1000000007
	MOD2 = 998244353
)

var (
	S_E = S{0, (1<<31 - 1)/2, -(1 << 31)/2}
	F_Id = F{0, 0}
)

type S struct {
	Sum int64
	L   int
	R   int
}

type F struct {
	D int64
	N int
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

var inv9 = modInv(9)

func opS(a, b S) S {
	sum := a.Sum + b.Sum
	if sum >= MOD2 {
		sum -= MOD2
	}
	newL := a.L
	if b.L < newL {
		newL = b.L
	}
	newR := a.R
	if b.R > newR {
		newR = b.R
	}
	return S{sum, newL, newR}
}

func mapS(f F, s S) S {
	n := f.N
	tenmodL := tenmod[n-s.L]
	var tenmodR int64
	if s.R == n-1 {
		tenmodR = 1 // since tenmod[0] is ScrollBar
	} else {
		tenmodR = tenmod[n-s.R-1]
	}
	c := (tenmodL - tenmodR) % MOD2
	if c < 0 {
		c += MOD2
	}
	sum := (f.D * c) % MOD2
	sum = (sum * inv9) % MOD2
	return S{sum: sum, L: s.L, R: s.R}
}

func compositeF(f, g F) F {
	return F{D: f.D, N: f.N}
}

type LazySegTree struct {
	Dat     []S
	Laz     []F
	N       int
	Log     int
	Op      func(a, b S) S
	E       S
	Mapping func(f F, s S) S
	Composition func(f, g F) F
	Id      F
	Max     int
}

func NewLazySegTree(data []S, op func(a, b S) S, e S, mapping func(f F, s S) S, composition func(f, g F) F, id F) *LazySegTree {
	n := len(data)
	size := 1
	for size < n {
		size <<= 1
	}
	log := bits.TrailingZeros(uint(size))
	dat := make([]S, 2*size)
	for i := range dat {
		dat[i] = e
	}
	copy(dat[size:], data)
	for i := size - 1; i > 0; i-- {
		dat[i] = op(dat[2*i], dat[2*i+1])
	}
	laz := make([]F, size)
	for i := range laz {
		laz[i] = id
	}
	return &LazySegTree{
		Dat: dat,
		Laz: laz,
		N: size,
		Log: log,
		Op: op,
		E: e,
		Mapping: mapping,
		Composition: composition,
		Id: id,
		Max: n,
	}
}

func (t *LazySegTree) push(k int) {
	if t.Laz[k] == t.Id {
		return
	}
	l := 2 * k
	r := 2*k + 1
	t.Dat[l] = t.Mapping(t.Laz[k], t.Dat[l])
	t.Dat[r] = t.Mapping(t.Laz[k], t.Dat[r])
	if l < t.N {
		t.Laz[l] = t.Composition(t.Laz[k], t.Laz[l])
	}
	if r < t.N {
		t.Laz[r] = t.Composition(t.Laz[k], t.Laz[r])
	}
	t.Laz[k] = t.Id
}

func (t *LazySegTree) pushTo(k int) {
	for i := t.Log; i > 0; i-- {
		t.push(k >> i)
	}
}

func (t *LazySegTree) pushToRange(l, r int) {
	for i := t.Log; i > 0; i-- {
		if ((l >> i) << i) != l {
			t.push(l >> i)
		}
		if ((r >> i) << i) != r {
			t.push(r >> i)
		}
	}
}

func (t *LazySegTree) updateFrom(l, r int) {
	for i := 1; i <= t.Log; i++ {
		if ((l >> i) << i) != l {
			lki := l >> i
			left := lki * 2
			right := left + 1
			t.Dat[lki] = t.Op(t.Dat[left], t.Dat[right])
		}
		if ((r >> i) << i) != r {
			rki := (r - 1) >> i
			left := rki * 2
			right := left + 1
			t.Dat[rki] = t.Op(t.Dat[left], t.Dat[right])
		}
	}
}

func (t *LazySegTree) apply(l, r int, f F) {
	if l >= r {
		return
	}
	l += t.N
	r += t.N
	t.pushToRange(l, r)
	for l < r {
		if l&1 == 1 {
			t.Dat[l] = t.Mapping(f, t.Dat[l])
			if l < t.N {
				t.Laz[l] = t.Composition(f, t.Laz[l])
			}
			l++
		}
		if r&1 == 1 {
			r--
			t.Dat[r] = t.Mapping(f, t.Dat[r])
			if r < t.N {
				t.Laz[r] = t.Composition(f, t.Laz[r])
			}
		}
		l >>= 1
		r >>= 1
	}
	t.updateFrom(l, r)
}

func (t *LazySegTree) allProd() S {
	return t.Dat[1]
}

type Reader struct {
	r *bufio.Reader
}

func NewReader(r io.Reader) *Reader {
	return &Reader{r: bufio.NewReader(r)}
}

func (rd *Reader) readByte() (byte, error) {
	return rd.r.ReadByte()
}

func (rd *Reader) skipSpace() {
	for {
		b, _ := rd.readByte()
		if b == ' ' || b == '	' || b == '
' || b == '' {
			continue
		} else {
			rad.r.UnreadByte()
			break
		}
	}
}

func (rd *Reader) readInt() int {
	rad.skipSpace()
	sign := 1
	if b, _ := rd.readByte(); b == '-' {
		sign = -1
	} else {
	rad.r.UnreadByte()
	}
	num := 0
	for {
		b, err := rd.readByte()
		if err != nil || b < '0' || b > '9' {
			break
		}
		num = num*10 + int(b - '0')
	}
	return sign * num
}

func (rd *Reader) readLong() int64 {
	rad.skipSpace()
	sign := int64(1)
	if b, _ := rd.readByte(); b == '-' {
		sign = -1
	} else {
	rad.r.UnreadByte()
	}
	num := int64(0)
	for {
		b, err := rd.readByte()
		if err != nil || b < '0' || b > '9' {
			break
		}
		num = num*10 + int64(b - '0')
	}
	return sign * num
}

var tenmod []int64

func main() {
	N := NewReader(os.Stdin).readInt()
	Q := NewReader(os.Stdin).readInt()
	tenmod = make([]int64, N+1)
	tenmod[0] = 1
	for i := 1; i <= N; i++ {
		tenmod[i] = (tenmod[i-1] * 10) % MOD2
	}
	data := make([]S, N)
	for i := 0; i < N; i++ {
		data[i] = S{
			Sum: tenmod[N-i-1],
			L:   i,
			R:   i,
		}
	}
	st := NewLazySegTree(data, opS, S_E, mapS, compositeF, F_Id)
	for i := 0; i < Q; i++ {
		rad := NewReader(os.Stdin)
		l := rad.readInt() - 1
		r := rad.readInt() - 1
		D := rad.readLong()
		st.apply(l, r+1, F{D: D, N: N})
		fmt.Println(st.allProd().Sum)
	}
} // End of Code
