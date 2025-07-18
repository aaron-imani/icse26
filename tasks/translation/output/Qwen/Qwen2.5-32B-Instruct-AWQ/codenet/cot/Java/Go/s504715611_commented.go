package main

import (
	"fmt"
	"math"
	"strconv"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{
		Parent: make([]int, n),
	}
	for i := range uf.Parent {
		uf.Parent[i] = -1
	}
	return uf
}

func (uf *UnionFind) root(A int) int {
	if uf.Parent[A] < 0 {
		return A
	}
	uf.Parent[A] = uf.root(uf.Parent[A])
	return uf.Parent[A]
}

func (uf *UnionFind) size(A int) int {
	return -uf.Parent[uf.root(A)]
}

func (uf *UnionFind) connect(A int, B int) bool {
	A = uf.root(A)
	B = uf.root(B)
	if A == B {
		return false
	}
	if uf.size(A) < uf.size(B) {
		A, B = B, A
	}
	uf.Parent[A] += uf.Parent[B]
	uf.Parent[B] = A
	return true
}

var scan = &FastScanner{in: make([]byte, 1024)}

func main() {
	str := scan.next()
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

type FastScanner struct {
	in []byte
	ptr int
	buflen int
}

func (fs *FastScanner) hasNextByte() bool {
	if fs.ptr < fs.buflen {
		return true
	} else {
		fs.ptr = 0
		fs.buflen = len(fs.in)
		return fs.buflen > 0
	}
}

func (fs *FastScanner) readByte() int {
	if fs.hasNextByte() {
		b := fs.in[fs.ptr]
		fs.ptr++
		return int(b)
	}
	return -1
}

func (fs *FastScanner) hasNext() bool {
	for fs.hasNextByte() && !isPrintableChar(fs.readByte()) {
	}
	return fs.hasNextByte()
}

func (fs *FastScanner) next() string {
	if !fs.hasNext() {
		panic("no next element")
	}
	var sb strings.Builder
	b := fs.readByte()
	for isPrintableChar(b) {
		sb.WriteByte(byte(b))
		b = fs.readByte()
	}
	return sb.String()
}

func (fs *FastScanner) nextLong() int64 {
	if !fs.hasNext() {
		panic("no next element")
	}
	n := int64(0)
	minus := false
	b := fs.readByte()
	if b == '-' {
		minus = true
		b = fs.readByte()
	}
	if b < '0' || '9' < b {
		panic("invalid number format")
	}
	for {
		if '0' <= b && b <= '9' {
			n *= 10
			n += int64(b - '0')
		} else if b == -1 || !isPrintableChar(b) {
			if minus {
				return -n
			}
			return n
		} else {
			panic("invalid number format")
		}
		b = fs.readByte()
	}
}

func (fs *FastScanner) nextInt() int {
	nl := fs.nextLong()
	if nl < math.MinInt32 || nl > math.MaxInt32 {
		panic("invalid number format")
	}
	return int(nl)
}

func (fs *FastScanner) nextDouble() float64 {
	return strconv.ParseFloat(fs.next(), 64)
}

func (fs *FastScanner) nextChar() byte {
	return byte(fs.readByte())
}

func isPrintableChar(c int) bool {
	return 33 <= c && c <= 126
}

// End of Code
