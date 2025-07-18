package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF  = 1<<62 - 1
	MOD  = 1000000007
	SIZE = 1000000
)

var (
	fac  = make([]int64, SIZE)
	inv  = make([]int64, SIZE)
	finv = make([]int64, SIZE)
	sc   = NewScanner()
)

func main() {
	newMain().solve()
}

type Main struct{}

func newMain() *Main {
	return &Main{}
}

func (m *Main) solve() {
	n := sc.nextInt()
	m := sc.nextInt()
	mapS := make(map[int]int)

	for i := 0; i < m; i++ {
		s := sc.nextInt()
		c := sc.nextInt()
		if val, exists := mapS[s]; exists && val != c {
			fmt.Println(-1)
			os.Exit(0)
		}
		mapS[s] = c
	}

	for i := 0; i < 1000; i++ {
		s := strconv.Itoa(i)
		flag := true
		if len(s) < n {
			continue
		}
		for j := 0; j < n; j++ {
			if val, exists := mapS[j+1]; exists && val != int(s[j]-'0') || (!exists && int(s[j]-'0') != 0) {
				if !exists && j == 0 && int(s[j]-'0') == 1 {
					continue
				}
				flag = false
				break
			}
		}
		if flag && len(s) == n {
			fmt.Println(s)
			os.Exit(0)
		}
	}

	fmt.Println(-1)
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
		if r&1 == 1 {
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

func (m *Main) initCOMB() {
	fac[0], fac[1] = 1, 1
	inv[1] = 1
	finv[0], finv[1] = 1, 1
	for i := 2; i < SIZE; i++ {
		fac[i] = fac[i-1] * int64(i) % MOD
		inv[i] = MOD - inv[MOD%int64(i)]*int64(MOD/int64(i))%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func (m *Main) modComb(n, r int) int64 {
	if n < r || n < 0 || r < 0 {
		return 0
	}
	return fac[n] * finv[r] % MOD * finv[n-r] % MOD
}

func comb(n, r int64) int64 {
	num := int64(1)
	for i := int64(1); i <= r; i++ {
		num = num * (n-i+1) / i
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
	list := strings.Split(s, "")
	pivotPos := -1
	var pivot byte
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
	var min byte = 255
	for i := R; i >= L; i-- {
		if pivot < list[i] {
			if list[i] < min {
				min = list[i]
				minPos = i
			}
		}
	}

	list[pivotPos], list[minPos] = list[minPos], list[pivotPos]
	for i, j := L, R; i < j; i, j = i+1, j-1 {
		list[i], list[j] = list[j], list[i]
	}

	return strings.Join(list, "")
}

func nextPermutationInt(a []int) bool {
	for i := len(a) - 1; i > 0; i-- {
		if a[i-1] < a[i] {
			swapIndex := find(a[i-1], a, i, len(a)-1)
			a[swapIndex], a[i-1] = a[i-1], a[swapIndex]
			sort.Ints(a[i:])
			return true
		}
	}
	return false
}

func find(dest int, a []int, s, e int) int {
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
		for i := n - 1; i >= 0; i-- {
			for j := i + 1; j < n; j++ {
				b[i] -= a[i][j] * b[j]
			}
			b[i] = b[i] / a[i][i]
		}
	}
}

type Pair struct {
	a, b int64
}

func (p Pair) CompareTo(q Pair) int {
	if p.b < q.b {
		return -1
	} else if p.b > q.b {
		return 1
	} else {
		return 0
	}
}

type Scanner struct {
	r *bufio.Reader
}

func NewScanner() *Scanner {
	r := bufio.NewReader(os.Stdin)
	return &Scanner{r: r}
}

func (s *Scanner) nextLine() string {
	buf := make([]byte, 0)
	for {
		l, p, err := s.r.ReadLine()
		if err != nil {
			if p {
				fmt.Fprintf(os.Stderr, "Unexpected byte at end of input: %v\n", l)
			}
			return ""
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

func (s *Scanner) next() string {
	for {
		t := strings.TrimSpace(s.nextLine())
		if t != "" {
			return t
		}
	}
}

func (s *Scanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *Scanner) nextInt64() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func (s *Scanner) nextFloat64() float64 {
	f, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return f
}

// End of Code
