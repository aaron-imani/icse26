package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	INF  = math.MaxInt64 / 2
	MOD  = 1_000_000_007
	SIZE = 1_000_000
)

var (
	fac  = make([]int64, SIZE)
	inv  = make([]int64, SIZE)
	finv = make([]int64, SIZE)
)

type FastScanner struct {
	in       []byte
	ptr      int
	buflen   int
	buffer   [1024]byte
	hasNext  bool
}

func (fs *FastScanner) hasNextByte() bool {
	if fs.ptr < fs.buflen {
		return true
	} else {
		fs.ptr = 0
		fs.buflen, fs.hasNext = fs.in.Read(fs.buffer[:])
		if fs.buflen <= 0 {
			return false
		}
	}
	return true
}

func (fs *FastScanner) readByte() int {
	if fs.hasNextByte() {
		return fs.buffer[fs.ptr]
	} else {
		return -1
	}
}

func (fs *FastScanner) hasNext() bool {
	for fs.hasNextByte() && !isPrintableChar(fs.buffer[fs.ptr]) {
		fs.ptr++
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

func isPrintableChar(c int) bool {
	return 33 <= c && c <= 126
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func inv(a int64) int64 {
	return pow(a, MOD-2)
}

func pow(a, r int64) int64 {
	sum := int64(1)
	for r > 0 {
		if (r & 1) == 1 {
			sum *= a
			sum %= MOD
		}
		a *= a
		a %= MOD
		r >>= 1
	}
	return sum
}

func modFact(n int64) int64 {
	if n == 0 {
		return 1
	}
	return n * modFact(n-1) % MOD
}

func fact(n int64) int64 {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func initCOMB() {
	fac[0] = 1
	fac[1] = 1
	inv[1] = 1
	finv[0] = 1
	finv[1] = 1
	for i := 2; i < SIZE; i++ {
		fac[i] = fac[i-1] * int64(i) % MOD
		inv[i] = MOD - inv[MOD%int64(i)]*(MOD/int64(i))%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func modComb(n, r int) int64 {
	if n < r || n < 0 || r < 0 {
		return 0
	}
	return fac[n] * finv[r] % MOD * finv[n-r] % MOD
}

func comb(n, r int64) int64 {
	num := int64(1)
	for i := int64(1); i <= r; i++ {
		num = num * (n - i + 1) / i
	}
	return num
}

func isPrime(a int64) bool {
	if a <= 1 {
		return false
	}
	for i := int64(2); i*i <= a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func nextPermutation(s string) string {
	list := []rune(s)
	pivotPos := -1
	pivot := rune(0)
	for i := len(list) - 2; i >= 0; i-- {
		if list[i] < list[i+1] {
			pivotPos = i
			pivot = list[i]
			break
		}
	}
	if pivotPos == -1 && pivot == 0 {
		return ""
	}
	L := pivotPos + 1
	R := len(list) - 1
	minPos := -1
	min := rune(math.MaxInt32)
	for i := R; i >= L; i-- {
		if pivot < list[i] {
			if list[i] < min {
				min = list[i]
				minPos = i
			}
		}
	}
	list[pivotPos], list[minPos] = list[minPos], list[pivotPos]
	sort.Slice(list[L:R+1], func(i, j int) bool {
		return list[L+i] < list[L+j]
	})
	return string(list)
}

func nextPermutation(a []int64) bool {
	for i := len(a) - 1; i > 0; i-- {
		if a[i-1] < a[i] {
			swapIndex := find(a[i-1], a, i, len(a)-1)
			a[i-1], a[swapIndex] = a[swapIndex], a[i-1]
			sort.Slice(a[i:], func(i, j int) bool {
				return a[i] < a[j]
			})
			return true
		}
	}
	return false
}

func find(dest int64, a []int64, s, e int) int {
	if s == e {
		return s
	}
	m := (s + e + 1) / 2
	if a[m] <= dest {
		return find(dest, a, s, m-1)
	}
	return find(dest, a, m, e)
}

func elimination(a [][]int, b []int) {
	n := len(a)
	var f float64
	for k := 0; k < n-1; k++ {
		for i := k + 1; i < n; i++ {
			f = -float64(a[i][k]) / float64(a[k][k])
			for j := k + 1; j < n; j++ {
				a[i][j] += int(f * float64(a[k][j]))
			}
			b[i] += int(f * float64(b[k]))
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			b[i] -= a[i][j] * b[j]
		}
		b[i] = b[i] / a[i][i]
	}
}

type Pair struct {
	a int64
	b int64
}

func (p Pair) Less(o Pair) bool {
	return p.b < o.b
}

func (p Pair) Equal(o Pair) bool {
	return p.b == o.b
}

func (p Pair) Greater(o Pair) bool {
	return p.b > o.b
}

func solve(sc *FastScanner) {
	n := sc.nextInt()
	m := sc.nextInt()
	map := make(map[int]int)
	for i := 0; i < m; i++ {
		s := sc.nextInt()
		c := sc.nextInt()
		if v, ok := map[s]; ok && v != c {
			fmt.Println(-1)
			return
		}
		map[s] = c
	}
	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		flag := true
		if len(s) < n {
			continue
		}
		for j := 0; j < n; j++ {
			if v, ok := map[j+1]; ok && v != int(s[j]-'0') || !ok && int(s[j]-'0') != 0 {
				if !ok && j == 0 && int(s[j]-'0') == 1 {
					continue
				}
				flag = false
				break
			}
		}
		if flag && len(s) == n {
			fmt.Println(s)
			return
		}
	}
	fmt.Println(-1)
}

func main() {
	sc := &FastScanner{in: os.Stdin}
	solve(sc)
	// End of Code
}
