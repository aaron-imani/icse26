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
		g.dt[i] = NewNode0n()
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
	for i := 0; i < len(g.dt); i++ {
		g.dt[i].Clear()
	}
}

type Node0n struct {
	next_vs []int
}

func NewNode0n() *Node0n {
	return &Node0n{next_vs: make([]int, 0)}
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
	from, v2 int
	weight   int64
}

func NewEdge(vn int, w int64) *Edge {
	return &Edge{v2: vn, weight: w}
}

func NewEdgeWithFrom(cm, vn int, w int64) *Edge {
	return &Edge{from: cm, v2: vn, weight: w}
}

type Edge2 struct {
	v2     int
	cost1, cost2 int64
}

func NewEdge2(vn int, w1, w2 int64) *Edge2 {
	return &Edge2{v2: vn, cost1: w1, cost2: w2}
}

type ComparatorEdge struct{}

func (ce ComparatorEdge) Compare(a, b *Edge) int {
	if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return b.v2 - a.v2
	}
}

type V2Comp struct{}

func (v2c V2Comp) Compare(a, b *Edge) int {
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

func (av2 AntiV2) Compare(a, b *Edge) int {
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

func NewVector(sx, sy int) *Vector {
	return &Vector{x: sx, y: sy}
}

const (
	INF  = 1e8
	INFL = 1e17
	e97  = 1e9 + 7
)

func main() {
	sc := NewFastScanner()
	n := sc.NextInt()
	s := sc.Next()
	flaged := make([]bool, n)
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			flaged[i] = true
		}
	}

	pop1st := int64(0)
	for i := 0; i < n; i++ {
		if flaged[i] {
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

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func abs64(a int64) int64 {
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

func min64(a, b int64) int64 {
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

func max64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func minN(ins ...int) int {
	min := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] < min {
			min = ins[i]
		}
	}
	return min
}

func maxN(ins ...int) int {
	max := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] > max {
			max = ins[i]
		}
	}
	return max
}

func minN64(ins ...int64) int64 {
	min := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] < min {
			min = ins[i]
		}
	}
	return min
}

func maxN64(ins ...int64) int64 {
	max := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] > max {
			max = ins[i]
		}
	}
	return max
}

func minExAd(dt []int, ad int) int {
	min := INF
	for i := 0; i < len(dt); i++ {
		if i != ad && dt[i] < min {
			min = dt[i]
		}
	}
	return min
}

func minExAd64(dt []int64, ad int) int64 {
	min := INFL
	for i := 0; i < len(dt); i++ {
		if i != ad && dt[i] < min {
			min = dt[i]
		}
	}
	return min
}

func minExVal(dt []int, ex_val int) int {
	min := INF
	for i := 0; i < len(dt); i++ {
		if dt[i] != ex_val && dt[i] < min {
			min = dt[i]
		}
	}
	return min
}

func minExVal64(dt []int64, ex_val int64) int64 {
	min := INFL
	for i := 0; i < len(dt); i++ {
		if dt[i] != ex_val && dt[i] < min {
			min = dt[i]
		}
	}
	return min
}

func maxExAd(dt []int, ad int) int {
	max := -INF
	for i := 0; i < len(dt); i++ {
		if i != ad && dt[i] > max {
			max = dt[i]
		}
	}
	return max
}

func maxExAd64(dt []int64, ad int) int64 {
	max := -INFL
	for i := 0; i < len(dt); i++ {
		if i != ad && dt[i] > max {
			max = dt[i]
		}
	}
	return max
}

func maxExVal(dt []int, ex_val int) int {
	max := -INF
	for i := 0; i < len(dt); i++ {
		if dt[i] != ex_val && dt[i] > max {
			max = dt[i]
		}
	}
	return max
}

func maxExVal64(dt []int64, ex_val int64) int64 {
	max := -INFL
	for i := 0; i < len(dt); i++ {
		if dt[i] != ex_val && dt[i] > max {
			max = dt[i]
		}
	}
	return max
}

func sumA(dt []int) int {
	sum := 0
	for _, e := range dt {
		sum += e
	}
	return sum
}

func sumA64(dt []int64) int64 {
	sum := int64(0)
	for _, e := range dt {
		sum += e
	}
	return sum
}

func same3(a, b, c int64) bool {
	if a != b {
		return false
	}
	if b != c {
		return false
	}
	if c != a {
		return false
	}
	return true
}

func dif3(a, b, c int64) bool {
	if a == b {
		return false
	}
	if b == c {
		return false
	}
	if c == a {
		return false
	}
	return true
}

func triangleInequality(a, b, c int) bool {
	if (a+b) < c {
		return false
	}
	if (b+c) < a {
		return false
	}
	if (c+a) < b {
		return false
	}
	return true
}

func hypod(a, b float64) float64 {
	return math.Sqrt(a*a + b*b)
}

func factorial(n int) int64 {
	ans := int64(1)
	for i := int64(n); i > 0; i-- {
		ans *= i
	}
	return ans
}

func facP(n int, p int64) int64 {
	ans := int64(1)
	for i := int64(n); i > 0; i-- {
		ans *= i
		ans %= p
	}
	return ans
}

func lcm(m, n int64) int64 {
	ans := m / gcd(m, n)
	ans *= n
	return ans
}

func gcd(m, n int64) int64 {
	if m < n {
		return gcd(n, m)
	}
	if n == 0 {
		return m
	}
	return gcd(n, m%n)
}

func isPrime(a int64) bool {
	if a == 1 {
		return false
	}
	for i := int64(2); i <= int64(math.Sqrt(float64(a))); i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func modinv(a, p int64) int64 {
	b, u, v := p, int64(1), int64(0)
	for b > 0 {
		t := a / b
		pe := a % b
		a, b = b, pe
		pe = u - t*v
		u, v = v, pe
	}
	u %= p
	if u < 0 {
		u += p
	}
	return u
}

func pow(n, k int) int {
	ans := 1
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow64(n int64, k int) int64 {
	ans := int64(1)
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow2(in int) int {
	return in * in
}

func pow264(in int64) int64 {
	return in * in
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

func getDigit10(num int64) int {
	cf := int64(1)
	d := 0
	for num >= cf {
		d++
		cf *= 10
	}
	return d
}

func isINF(in int) bool {
	if int64(in)*20 > INF {
		return true
	}
	return false
}

func isINFL(in int64) bool {
	if in*10000 > INFL {
		return true
	}
	return false
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
	obPow2Pow := make([]int64, d)

	obPow2Pow[0] = ob
	for i := 1; i < d; i++ {
		obPow2Pow[i] = (obPow2Pow[i-1] * obPow2Pow[i-1]) % p
	}

	ans := int64(1)
	for i := d - 1; i >= 0; i-- {
		if soeji >= (1 << i) {
			soeji -= (1 << i)
			ans = (ans * obPow2Pow[i]) % p
		}
	}
	return ans % p
}

func flag(pos int) int64 {
	return (1 << pos)
}

func isFlaged(bit int, pos int) bool {
	if (bit&(1<<pos)) > 0 {
		return true
	}
	return false
}

func isFlaged64(bit int64, pos int) bool {
	if (bit&(1<<pos)) > 0 {
		return true
	}
	return false
}

func deflag(bit int, pos int) int {
	return bit & ^(1 << pos)
}

func countFlaged(bit int) int {
	ans := 0
	for i := 0; i < getDigit2(int64(bit)); i++ {
		if (bit&(1<<i)) > 0 {
			ans++
		}
	}
	return ans
}

func countFlaged64(bit int64) int {
	ans := 0
	for i := int64(0); i < getDigit2(bit); i++ {
		if (bit&(1<<i)) > 0 {
			ans++
		}
	}
	return ans
}

func showflag(bit int) {
	for i := 0; i < getDigit2(int64(bit)); i++ {
		if isFlaged(bit, i) {
			fmt.Print("O")
		} else {
			fmt.Print(".")
		}
	}
	fmt.Println()
}

func biSearch(dt []int, target int) int {
	left, right := 0, len(dt)-1
	var mid int
	for left <= right {
		mid = (right + left) / 2
		if dt[mid] == target {
			return mid
		}
		if dt[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1
}

func biSearchMax(dt []int64, target int64) int {
	left, right := -1, len(dt)
	var mid int
	for (right - left) > 1 {
		mid = left + (right-left)/2
		if dt[mid] <= target {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func biSearchMaxAL(dt []int, target int64) int {
	left, right := -1, len(dt)
	var mid int
	for (right - left) > 1 {
		mid = left + (right-left)/2
		if int64(dt[mid]) <= target {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func fillParent(ob []int) {
	for i := 0; i < len(ob); i++ {
		ob[i] = i
	}
}

func getRootUF(parent []int, index int) int {
	if parent[index] == index {
		return index
	}
	root := getRootUF(parent, parent[index])
	parent[index] = root
	return root
}

func isSameUF(parent []int, x, y int) bool {
	if getRootUF(parent, x) == getRootUF(parent, y) {
		return true
	}
	return false
}

func uniteUF(parent []int, receiver, attacker int) {
	parent[getRootUF(parent, attacker)] = getRootUF(parent, receiver)
}

var (
	Xdir4 = []int{1, 0, 0, -1}
	Ydir4 = []int{0, 1, -1, 0}
)

var (
	Xdir8 = []int{1, 1, 1, 0, 0, -1, -1, -1}
	Ydir8 = []int{1, 0, -1, 1, -1, 1, 0, -1}
)

func isInArea(y, x, h, w int) bool {
	if y < 0 {
		return false
	}
	if x < 0 {
		return false
	}
	if y >= h {
		return false
	}
	if x >= w {
		return false
	}
	return true
}

func show2(dt [][]bool, litX, litY int) {
	for j := 0; j < len(dt); j++ {
		for i := 0; i < len(dt[j]); i++ {
			if i == litY && j == litX {
				fmt.Print("X")
			} else if dt[j][i] {
				fmt.Print("O")
			} else {
				fmt.Print(".")
			}
		}
		fmt.Println()
	}
}

func show2Int(dt [][]int, cmnt string) {
	for i := 0; i < len(dt); i++ {
		for j := 0; j < len(dt[i]); j++ {
			fmt.Printf("%d,", dt[i][j])
		}
		fmt.Printf("<-%s:%d\n", cmnt, i)
	}
}

func show2Int64(dt [][]int64, cmnt string) {
	for i := 0; i < len(dt); i++ {
		for j := 0; j < len(dt[i]); j++ {
			fmt.Printf("%d,", dt[i][j])
		}
		fmt.Printf("<-%s:%d\n", cmnt, i)
	}
}

func dispQue(dt []int64) {
	for len(dt) > 0 {
		a := dt[0]
		fmt.Print(a)
		dt = dt[1:]
	}
	fmt.Println("\n")
}

func dispList(dt []interface{}) {
	for i := 0; i < len(dt); i++ {
		fmt.Printf("%v,", dt[i])
	}
	fmt.Println("\n")
}

func prtlnas(as []int) {
	for i := 0; i < len(as); i++ {
		fmt.Println(as[i])
	}
}

func prtlnas64(as []int64) {
	for i := 0; i < len(as); i++ {
		fmt.Println(as[i])
	}
}

func prtspas(as []int) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Printf(" %d", as[i])
	}
	fmt.Println()
}

func prtspas64(as []int64) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Printf(" %d", as[i])
	}
	fmt.Println()
}

func prtspasInterface(as []interface{}) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Printf(" %v", as[i])
	}
	fmt.Println()
}

func fillBool(ob []bool, res bool) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fillInt(ob []int, res int) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fillInt64(ob []int64, res int64) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fillChar(ob []byte, res byte) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fillDouble(ob []float64, res float64) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fillBool2(ob [][]bool, res bool) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fillInt2(ob [][]int, res int) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fillInt642(ob [][]int64, res int64) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fillChar2(ob [][]byte, res byte) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fillDouble2(ob [][]float64, res float64) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fillInt3(ob [][][]int, res int) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			for k := 0; k < len(ob[0][0]); k++ {
				ob[i][j][k] = res
			}
		}
	}
}

func fillInt643(ob [][][]int64, res int64) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			for k := 0; k < len(ob[0][0]); k++ {
				ob[i][j][k] = res
			}
		}
	}
}

type FastScanner struct {
	r *bufio.Reader
}

func NewFastScanner() *FastScanner {
	r := bufio.NewReader(os.Stdin)
	return &FastScanner{r: r}
}

func (s *FastScanner) Next() string {
	var buf []byte = make([]byte, 0)
	for {
		b, p, e := s.r.ReadRune()
		if e != nil {
			panic(e)
		}
		if p == 0 {
			break
		}
		if b == ' ' || b == '\n' {
			break
		}
		buf = append(buf, byte(b))
	}
	return string(buf)
}

func (s *FastScanner) NextInt() int {
	i, e := strconv.Atoi(s.Next())
	if e != nil {
		panic(e)
	}
	return i
}

func (s *FastScanner) NextInt64() int64 {
	i, e := strconv.ParseInt(s.Next(), 10, 64)
	if e != nil {
		panic(e)
	}
	return i
}

func (s *FastScanner) NextFloat64() float64 {
	f, e := strconv.ParseFloat(s.Next(), 64)
	if e != nil {
		panic(e)
	}
	return f
}

func (s *FastScanner) NextLine() string {
	var buf []byte = make([]byte, 0)
	for {
		b, p, e := s.r.ReadRune()
		if e != nil {
			panic(e)
		}
		if p == 0 {
			break
		}
		if b == '\n' {
			break
		}
		buf = append(buf, byte(b))
	}
	return string(buf)
}

func (s *FastScanner) NextLines(n int) []string {
	lines := make([]string, n)
	for i := 0; i < n; i++ {
		lines[i] = s.NextLine()
	}
	return lines
}

func (s *FastScanner) NextInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = s.NextInt()
	}
	return ints
}

func (s *FastScanner) NextInt64s(n int) []int64 {
	int64s := make([]int64, n)
	for i := 0; i < n; i++ {
		int64s[i] = s.NextInt64()
	}
	return int64s
}

func (s *FastScanner) NextFloat64s(n int) []float64 {
	float64s := make([]float64, n)
	for i := 0; i < n; i++ {
		float64s[i] = s.NextFloat64()
	}
	return float64s
}

func (s *FastScanner) NextInts2(n, m int) [][]int {
	ints := make([][]int, n)
	for i := 0; i < n; i++ {
		ints[i] = s.NextInts(m)
	}
	return ints
}

func (s *FastScanner) NextInt64s2(n, m int) [][]int64 {
	int64s := make([][]int64, n)
	for i := 0; i < n; i++ {
		int64s[i] = s.NextInt64s(m)
	}
	return int64s
}

func (s *FastScanner) NextFloat64s2(n, m int) [][]float64 {
	float64s := make([][]float64, n)
	for i := 0; i < n; i++ {
		float64s[i] = s.NextFloat64s(m)
	}
	return float64s
}

func (s *FastScanner) NextWords() []string {
	return strings.Fields(s.NextLine())
}

// End of Code
