package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	parent := make([]int, n)
	for i := range parent {
		parent[i] = -1
	}
	return &UnionFind{Parent: parent}
}

func (uf *UnionFind) Root(a int) int {
	if uf.Parent[a] < 0 {
		return a
	}
	uf.Parent[a] = uf.Root(uf.Parent[a])
	return uf.Parent[a]
}

func (uf *UnionFind) Size(a int) int {
	return -uf.Parent[uf.Root(a)]
}

func (uf *UnionFind) Connect(a, b int) bool {
	a = uf.Root(a)
	b = uf.Root(b)
	if a == b {
		return false
	}
	if uf.Size(a) < uf.Size(b) {
		a, b = b, a
	}
	uf.Parent[a] += uf.Parent[b]
	uf.Parent[b] = a
	return true
}

var (
	scanner = bufio.NewScanner(os.Stdin)
	r       = strings.NewReader("")
	w       = bufio.NewWriter(os.Stdout)
)

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextString())
	return i
}

func nextInts(n int) []int {
	s := nextString()
	l := strings.Split(s, " ")
	is := make([]int, n)
	for i := range is {
		is[i], _ = strconv.Atoi(l[i])
	}
	return is
}

func main() {
	defer w.Flush()
	scanner.Split(bufio.ScanWords)
	str := nextString()
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
