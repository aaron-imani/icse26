package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Solver struct {
	in  *MyInput
	out *bufio.Writer
}

func (s *Solver) solve() {
	H := s.in.nextInt()
	W := s.in.nextInt()
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}
	for i := 0; i < H; i++ {
		line := s.in.nextString()
		for j, c := range line {
			C[i+1][j+1] = c
		}
	}
	if H == 1 && W == 1 {
		s.out.WriteString("No\n")
		return
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' &&
				C[i][j-1] != '#' && C[i][j+1] != '#' {
				s.out.WriteString("No\n")
				return
			}
		}
	}
	s.out.WriteString("Yes\n")
}

type MapCounter struct {
	Map map[int]int
}

func NewMapCounter() *MapCounter {
	return &MapCounter{Map: make(map[int]int)}
}

func (mc *MapCounter) add(key int) {
	mc.addWithCount(key, 1)
}

func (mc *MapCounter) addWithCount(key, cnt int) {
	mc.Map[key] += cnt
}

func (mc *MapCounter) remove(key int) {
	mc.subWithCount(key, 1, false)
}

func (mc *MapCounter) sub(key int) {
	mc.subWithCount(key, 1)
}

func (mc *MapCounter) subWithCount(key, cnt int) {
	mc.subWithCount(key, cnt, true)
}

func (mc *MapCounter) subWithCount(key, cnt int, minus bool) {
	if val, exists := mc.Map[key]; exists {
		if val > cnt || minus {
			mc.Map[key] = val - cnt
		} else {
			delete(mc.Map, key)
		}
	} else if minus {
		mc.Map[key] = -cnt
	}
}

func (mc *MapCounter) set(key, cnt int) {
	mc.Map[key] = cnt
}

func (mc *MapCounter) getCountWithNull(key int) int {
	if val, exists := mc.Map[key]; exists {
		return val
	}
	return 0
}

func (mc *MapCounter) getCount(key int) int {
	return mc.getCountWithNull(key)
}

func (mc *MapCounter) getKey() []int {
	keys := make([]int, 0, len(mc.Map))
	for k := range mc.Map {
		keys = append(keys, k)
	}
	return keys
}

func (mc *MapCounter) getKeyCount() int {
	return len(mc.Map)
}

func (mc *MapCounter) getFirstKey() int {
	minKey := 0
	first := true
	for k := range mc.Map {
		if first || k < minKey {
			minKey = k
			first = false
		}
	}
	return minKey
}

func (mc *MapCounter) getLastKey() int {
	maxKey := 0
	first := true
	for k := range mc.Map {
		if first || k > maxKey {
			maxKey = k
			first = false
		}
	}
	return maxKey
}

func (mc *MapCounter) clear() {
	mc.Map = make(map[int]int)
}

func isRightMin(a []int, f bool, index, key int) bool {
	if f && a[index] >= key {
		return true
	} else if !f && a[index] > key {
		return true
	}
	return false
}

func binarySearchRightMin(a []int, f bool, key int) int {
	ng := -1
	ok := len(a)
	for ok-ng > 1 {
		mid := (ok + ng) / 2
		if isRightMin(a, f, mid, key) {
			ok = mid
		} else {
			ng = mid
		}
	}
	return ok
}

func isLeftMax(a []int, f bool, index, key int) bool {
	if f && a[index] <= key {
		return true
	} else if !f && a[index] < key {
		return true
	}
	return false
}

func binarySearchLeftMax(a []int, f bool, key int) int {
	ng := -1
	ok := len(a)
	for ok-ng > 1 {
		mid := (ok + ng) / 2
		if isLeftMax(a, f, mid, key) {
			ng = mid
		} else {
			ok = mid
		}
	}
	return ng
}

type EulerTour struct {
	g     *Graph
	tour  []int
	begin []int
	end   []int
	k     int
	root  int
}

func (et *EulerTour) dfs(v, p int) {
	et.begin[v] = et.k
	et.tour = append(et.tour, v)
	et.k++
	if !et.g.contains(v) {
		return
	}
	for _, i := range et.g.get(v) {
		if i != p {
			et.dfs(i, v)
			et.tour = append(et.tour, v)
			et.k++
		}
	}
	et.end[v] = et.k
}

func (et *EulerTour) init(pCnt, root int, g *Graph) {
	et.begin = make([]int, pCnt+1)
	et.end = make([]int, pCnt+1)
	et.root = root
	et.g = g
	et.dfs(root, -1)
}

func (et *EulerTour) getPartTour(v int) []int {
	return et.tour[et.begin[v]:et.end[v]]
}

func (et *EulerTour) getPartList(v int) []int {
	set := make(map[int]struct{})
	for _, p := range et.getPartTour(v) {
		set[p] = struct{}{}
	}
	ans := make([]int, 0, len(set))
	for p := range set {
		ans = append(ans, p)
	}
	return ans
}

type Graph struct {
	data map[int][]int
}

func NewGraph() *Graph {
	return &Graph{data: make(map[int][]int)}
}

func (g *Graph) add(from, to int) {
	g.data[from] = append(g.data[from], to)
}

func (g *Graph) del(from, to int) {
	if list, exists := g.data[from]; exists {
		for i, v := range list {
			if v == to {
				g.data[from] = append(list[:i], list[i+1:]...)
				break
			}
		}
	}
}

func (g *Graph) get(key int) []int {
	return g.data[key]
}

func (g *Graph) contains(key int) bool {
	_, exists := g.data[key]
	return exists
}

func (g *Graph) keySet() []int {
	keys := make([]int, 0, len(g.data))
	for k := range g.data {
		keys = append(keys, k)
	}
	return keys
}

func (g *Graph) isConnect(key1, key2 int) bool {
	for _, v := range g.get(key1) {
		if v == key2 {
			return true
		}
	}
	return false
}

func (g *Graph) distList(key int) []PP {
	dist := make([]PP, 0)
	mark := make(map[int]struct{})
	stack := []PP{{key, 0}}
	for len(stack) > 0 {
		wk := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		pp := wk.key
		dd := wk.val
		mark[pp] = struct{}{}
		dist = append(dist, wk)
		for _, next := range g.get(pp) {
			if _, exists := mark[next]; exists {
				continue
			}
			stack = append(stack, PP{next, dd + 1})
		}
	}
	return dist
}

func (g *Graph) distV(key int) []int {
	dist := make([]int, len(g.data)+1)
	for i := range dist {
		dist[i] = -1
	}
	mark := make(map[int]struct{})
	stack := []PP{{key, 0}}
	for len(stack) > 0 {
		wk := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		pp := wk.key
		dd := wk.val
		mark[pp] = struct{}{}
		dist[pp] = dd
		for _, next := range g.get(pp) {
			if _, exists := mark[next]; exists {
				continue
			}
			stack = append(stack, PP{next, dd + 1})
		}
	}
	return dist
}

type PP struct {
	key, val int
}

type GraphWith struct {
	data map[int][]PP
}

func NewGraphWith() *GraphWith {
	return &GraphWith{data: make(map[int][]PP)}
}

func (g *GraphWith) add(key int, p PP) {
	g.data[key] = append(g.data[key], p)
}

func (g *GraphWith) get(key int) []PP {
	return g.data[key]
}

func (g *GraphWith) contains(key int) bool {
	_, exists := g.data[key]
	return exists
}

func (g *GraphWith) keySet() []int {
	keys := make([]int, 0, len(g.data))
	for k := range g.data {
		keys = append(keys, k)
	}
	return keys
}

func (g *GraphWith) isConnect(key1, key2 int) bool {
	for _, p := range g.get(key1) {
		if p.key == key2 {
			return true
		}
	}
	return false
}

func (g *GraphWith) distance(key1, key2 int) int {
	mark := make(map[int]struct{})
	stack := []PP{{key1, 0}}
	for len(stack) > 0 {
		wk := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		key := wk.key
		val := wk.val
		mark[key] = struct{}{}
		if key == key2 {
			return val
		}
		for _, pp := range g.get(key) {
			if _, exists := mark[pp.key]; exists {
				continue
			}
			stack = append(stack, PP{pp.key, val + pp.val})
		}
	}
	return 1<<31 - 1
}

type GraphLong struct {
	data map[int64][]int64
}

func NewGraphLong() *GraphLong {
	return &GraphLong{data: make(map[int64][]int64)}
}

func (g *GraphLong) add(key, value int64) {
	g.data[key] = append(g.data[key], value)
}

func (g *GraphLong) get(key int64) []int64 {
	return g.data[key]
}

type GraphLongWith struct {
	data map[int64][]PPL
}

func NewGraphLongWith() *GraphLongWith {
	return &GraphLongWith{data: make(map[int64][]PPL)}
}

func (g *GraphLongWith) add(key int64, p PPL) {
	g.data[key] = append(g.data[key], p)
}

func (g *GraphLongWith) get(key int64) []PPL {
	return g.data[key]
}

type PPL struct {
	key, val int64
}

func main() {
	in := NewMyInput(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solver := &Solver{in: in, out: out}
	solver.solve()
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(r io.Reader) *MyInput {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &MyInput{scanner: scanner}
}

func (m *MyInput) nextInt() int {
	m.scanner.Scan()
	i, _ := strconv.Atoi(m.scanner.Text())
	return i
}

func (m *MyInput) nextLong() int64 {
	m.scanner.Scan()
	i, _ := strconv.ParseInt(m.scanner.Text(), 10, 64)
	return i
}

func (m *MyInput) nextDouble() float64 {
	m.scanner.Scan()
	i, _ := strconv.ParseFloat(m.scanner.Text(), 64)
	return i
}

func (m *MyInput) nextString() string {
	m.scanner.Scan()
	return m.scanner.Text()
}

// End of Code
