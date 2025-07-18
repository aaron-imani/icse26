package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
)

type Graph0n struct {
	dt []*Node0n
}

func NewGraph0n(sz int) *Graph0n {
	g := &Graph0n{}
	g.dt = make([]*Node0n, sz)
	for i := 0; i < sz; i++ {
		g.dt[i] = &Node0n{}
	}
	return g
}

func (g *Graph0n) Add(vn int, val int) {
	g.dt[vn].Add(val)
}

func (g *Graph0n) Add2(vn int, val int) {
	g.dt[vn].Add(val)
	g.dt[val].Add(vn)
}

func (g *Graph0n) Get(vn int, index int) int {
	return g.dt[vn].Get(index)
}

func (g *Graph0n) GetList(vn int) []int {
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
	n.next_vs = []int{}
}

type Edge struct {
	from, v2 int
	weight   int64
}

func NewEdge(vn int, w int64) *Edge {
	return &Edge{v2: vn, weight: w}
}

func NewEdgeWithFrom(cm int, vn int, w int64) *Edge {
	return &Edge{from: cm, v2: vn, weight: w}
}

type Edge2 struct {
	v2, cost1, cost2 int64
}

func NewEdge2(vn int, w1 int64, w2 int64) *Edge2 {
	return &Edge2{v2: int64(vn), cost1: w1, cost2: w2}
}

type ComparatorEdge struct{}

func (c *ComparatorEdge) Compare(a, b *Edge) int {
	if a.weight > b.weight {
		return -1
	} else if a.weight < b.weight {
		return 1
	} else {
		return int(b.v2 - a.v2)
	}
}

type V2Comp struct{}

func (c *V2Comp) Compare(a, b *Edge) int {
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

func (c *antiV2) Compare(a, b *Edge) int {
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

func NewVector(sx int, sy int) *Vector {
	return &Vector{x: sx, y: sy}
}

const (
	INF = int(1e8)
	INFL = int64(1e17)
	e97 = int64(1e9 + 7)
)

func assertion(b bool) {
	if !b {
		panic("Assertion failed")
	}
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func abs(a int64) int64 {
	if a >= 0 {
		return a
	}
	return -a
}

func abs(a float64) float64 {
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

func min(a, b int64) int64 {
	if a > b {
		return b
	}
	return a
}

func min(a, b float64) float64 {
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

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func minN(ins []int) int {
	min := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] < min {
			min = ins[i]
		}
	}
	return min
}

func minN(ins []int64) int64 {
	min := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] < min {
			min = ins[i]
		}
	}
	return min
}

func maxN(ins []int) int {
	max := ins[0]
	for i := 1; i < len(ins); i++ {
		if ins[i] > max {
			max = ins[i]
		}
	}
	return max
}

func maxN(ins []int64) int64 {
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

func minExAd(dt []int64, ad int) int64 {
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

func minExVal(dt []int64, ex_val int64) int64 {
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

func maxExAd(dt []int64, ad int) int64 {
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

func maxExVal(dt []int64, ex_val int64) int64 {
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

func sumA(dt []int64) int64 {
	sum := int64(0)
	for _, e := range dt {
		sum += e
	}
	return sum
}

func sumA(dt []float64) float64 {
	sum := float64(0)
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

func triangle_inequality(a, b, c int) bool {
	if a+b < c {
		return false
	}
	if b+c < a {
		return false
	}
	if c+a < b {
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

func is_prime(a int64) bool {
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
	b := p
	u := int64(1)
	v := int64(0)
	for b > 0 {
		t := a / b
		pe := a % b
		a = b
		b = pe
		pe = u - t*v
		u = v
		v = pe
	}
	u %= p
	if u < 0 {
		u += p
	}
	return u
}

func pow(n int, k int) int {
	ans := 1
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow(n int64, k int) int64 {
	ans := int64(1)
	for i := 0; i < k; i++ {
		ans *= n
	}
	return ans
}

func pow2(in int) int {
	return in * in
}

func pow2(in int64) int64 {
	return in * in
}

func pow2(in float64) float64 {
	return in * in
}

func getDigit2(num int64) int {
	cf := int64(1)
	d := 0
	for num >= cf {
		d++
		cf = (1 << d)
	}
	return d // numはd桁の数で、2^dより小さい
}

func getDigit10(num int64) int {
	cf := int64(1)
	d := 0
	for num >= cf {
		d++
		cf *= 10
	}
	return d // numはd桁の数で、10^dより小さい
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

func flag(pos int64) int64 {
	return (1 << pos)
}

func isFlaged(bit int, pos int) bool {
	if (bit & (1 << pos)) > 0 {
		return true
	}
	return false
}

func isFlaged(bit int64, pos int) bool {
	if (bit & (1 << pos)) > 0 {
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
		if (bit & (1 << i)) > 0 {
			ans++
		}
	}
	return ans
}

func countFlaged(bit int64) int {
	ans := 0
	for i := int64(0); i < getDigit2(bit); i++ {
		if (bit & (1 << i)) > 0 {
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
	left := 0
	right := len(dt) - 1
	mid := -1
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
	left := -1
	right := len(dt)
	mid := -1
	for (right - left) > 1 {
		mid = left + (right-left)/2
		if dt[mid] <= target {
			left = mid
		} else {
			right = mid
		}
	}
	return left // target未満の最大のaddress
}

func biSearchMaxAL(dt []int, target int64) int {
	left := -1
	right := len(dt)
	mid := -1
	for (right - left) > 1 {
		mid = left + (right-left)/2
		if dt[mid] <= target {
			left = mid
		} else {
			right = mid
		}
	}
	return left // target以下の最大のaddress
}

func fill_parent(ob []int) {
	for i := 0; i < len(ob); i++ {
		ob[i] = i
	}
}

func get_root_uf(parent []int, index int) int {
	if parent[index] == index {
		return index
	}
	root := get_root_uf(parent, parent[index])
	parent[index] = root
	return root
}

func is_same_uf(parent []int, x int, y int) bool {
	if get_root_uf(parent, x) == get_root_uf(parent, y) {
		return true
	}
	return false
}

func unite_uf(parent []int, receiver int, attacker int) {
	parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver)
}

var Xdir4 = []int{1, 0, 0, -1}
var Ydir4 = []int{0, 1, -1, 0}

var Xdir8 = []int{1, 1, 1, 0, 0, -1, -1, -1}
var Ydir8 = []int{1, 0, -1, 1, -1, 1, 0, -1}

func is_in_area(y, x, h, w int) bool {
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

func show2(dt [][]bool, lit_x, lit_y int) {
	for j := 0; j < len(dt); j++ {
		for i := 0; i < len(dt[j]); i++ {
			if i == lit_y && j == lit_x {
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

func show2(dt [][]int, cmnt string) {
	for i := 0; i < len(dt); i++ {
		for j := 0; j < len(dt[i]); j++ {
			fmt.Print(dt[i][j] + ",")
		}
		fmt.Println("<-" + cmnt + ":" + string(i))
	}
}

func show2(dt [][]int64, cmnt string) {
	for i := 0; i < len(dt); i++ {
		for j := 0; j < len(dt[i]); j++ {
			fmt.Print(dt[i][j] + ",")
		}
		fmt.Println("<-" + cmnt + ":" + string(i))
	}
}

func disp_que(dt []int64) {
	for _, a := range dt {
		fmt.Print(a)
	}
	fmt.Println("\n")
}

func disp_list(dt []interface{}) {
	for i := 0; i < len(dt); i++ {
		fmt.Print(dt[i] + ",")
	}
	fmt.Println("\n")
}

func prtlnas(as []int) {
	for _, a := range as {
		fmt.Println(a)
	}
}

func prtlnas(as []int64) {
	for _, a := range as {
		fmt.Println(a)
	}
}

func prtspas(as []int) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Print(" " + string(as[i]))
	}
	fmt.Println()
}

func prtspas(as []int64) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Print(" " + string(as[i]))
	}
	fmt.Println()
}

func prtspas(as []interface{}) {
	fmt.Print(as[0])
	for i := 1; i < len(as); i++ {
		fmt.Print(" " + string(as[i]))
	}
	fmt.Println()
}

func fill(ob []bool, res bool) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fill(ob []int, res int) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fill(ob []int64, res int64) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fill(ob []rune, res rune) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fill(ob []float64, res float64) {
	for i := 0; i < len(ob); i++ {
		ob[i] = res
	}
}

func fill(ob [][]bool, res bool) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fill(ob [][]int, res int) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fill(ob [][]int64, res int64) {
	for i := 0; i < len(ob); i++ {
		for j := 1; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fill(ob [][]rune, res rune) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fill(ob [][]float64, res float64) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			ob[i][j] = res
		}
	}
}

func fill(ob [][][]int, res int) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			for k := 0; k < len(ob[0][0]); k++ {
				ob[i][j][k] = res
			}
		}
	}
}

func fill(ob [][][]int64, res int64) {
	for i := 0; i < len(ob); i++ {
		for j := 0; j < len(ob[0]); j++ {
			for k := 0; k < len(ob[0][0]); k++ {
				ob[i][j][k] = res
			}
		}
	}
}

type FastScanner struct {
	in       *bufio.Reader
	buffer   []byte
	ptr      int
	buflen   int
}

func NewFastScanner() *FastScanner {
	return &FastScanner{
		in: bufio.NewReader(os.Stdin),
		buffer: make([]byte, 1024),
		ptr: 0,
		buflen: 0,
	}
}

func (fs *FastScanner) hasNextByte() bool {
	if fs.ptr < fs.buflen {
		return true
	} else {
		fs.ptr = 0
		fs.buflen, _ = fs.in.Read(fs.buffer)
		if fs.buflen <= 0 {
			return false
		}
	}
	return true
}

func (fs *FastScanner) readByte() int {
	if fs.hasNextByte() {
		return int(fs.buffer[fs.ptr])
	}
	return -1
}

func (fs *FastScanner) isPrintableChar(b int) bool {
	return 33 <= b && b <= 126
}

func (fs *FastScanner) hasNext() bool {
	for fs.hasNextByte() && !fs.isPrintableChar(fs.buffer[fs.ptr]) {
		fs.ptr++
	}
	return fs.hasNextByte()
}

func (fs *FastScanner) next() string {
	if !fs.hasNext() {
		panic("No next element")
	}
	var sb strings.Builder
	b := fs.readByte()
	for fs.isPrintableChar(b) {
		sb.WriteByte(byte(b))
		b = fs.readByte()
	}
	return sb.String()
}

func (fs *FastScanner) nexL() int64 {
	if !fs.hasNext() {
		panic("No next element")
	}
	n := int64(0)
	minus := false
	b := fs.readByte()
	if b == '-' {
		minus = true
		b = fs.readByte()
	}
	if b < '0' || '9' < b {
		panic("Invalid number format")
	}
	for {
		if '0' <= b && b <= '9' {
			n *= 10
			n += int64(b - '0')
		} else if b == -1 || !fs.isPrintableChar(b) || b == ':' {
			if minus {
				return -n
			}
			return n
		} else {
			panic("Invalid number format")
		}
		b = fs.readByte()
	}
}

func (fs *FastScanner) nexI() int {
	nl := fs.nexL()
	if nl < math.MinInt32 || nl > math.MaxInt32 {
		panic("Number out of range")
	}
	return int(nl)
}

func (fs *FastScanner) nexD() float64 {
	return float64(fs.nexL())
}

func (fs *FastScanner) ni(array2 []int64) {
	for i := 0; i < len(array2); i++ {
		array2[i] = fs.nexL()
	}
}

func (fs *FastScanner) ni(array2 []int) {
	for i := 0; i < len(array2); i++ {
		array2[i] = fs.nexI()
	}
}

func (fs *FastScanner) ni(as, bs []int) {
	for i := 0; i < len(as); i++ {
		as[i] = fs.nexI()
		bs[i] = fs.nexI()
	}
}

func (fs *FastScanner) ni(as, bs []int64) {
	for i := 0; i < len(as); i++ {
		as[i] = fs.nexL()
		bs[i] = fs.nexL()
	}
}

func (fs *FastScanner) ni(as, bs, cs []int) {
	for i := 0; i < len(as); i++ {
		as[i] = fs.nexI()
		bs[i] = fs.nexI()
		cs[i] = fs.nexI()
	}
}

func (fs *FastScanner) nisan(as [][]int) {
	for i := 0; i < len(as); i++ {
		for j := 0; j < len(as[0]); j++ {
			as[i][j] = fs.nexI()
		}
	}
}

func main() {
	fs := NewFastScanner()
	var out = bufio.NewWriter(os.Stdout)

	n := fs.nexI()
	s := fs.next()
	flaged := make([]bool, n)
	for i := 0; i < n; i++ {
		flaged[i] = false
	}

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
				fmt.Fprintln(out, 0)
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
					fmt.Fprintln(out, 1/0)
				}
				count := countFlaged(dw)
				dw %= count
				ans++
			}
			fmt.Fprintln(out, ans)
		} else {
			dw := surp1
			dif := pow10E97(2, n-p-1, pop1st+1)
			dw += dif
			dw %= (pop1st + 1)
			ans := 1
			for dw != 0 {
				if dw < 0 {
					fmt.Fprintln(out, 1/0)
				}
				count := countFlaged(dw)
				dw %= count
				ans++
			}
			fmt.Fprintln(out, ans)
		}
	}

	out.Flush()
}
// End of Code
