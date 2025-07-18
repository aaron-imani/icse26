package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF  = 1<<63 - 1
	MOD  = 1_000_000_007
	SIZE = 1_000_000
)

type Main struct {
	fac  [SIZE]int64
	inv  [SIZE]int64
	finv [SIZE]int64
	sc   *FastScanner
}

func main() {
	new(Main).solve()
}

func (m *Main) solve() {
	m.sc = NewFastScanner(os.Stdin)
	n := m.sc.nextInt()
	m := m.sc.nextInt()
	mapS := make(map[int]int)

	for i := 0; i < m; i++ {
		s := m.sc.nextInt()
		c := m.sc.nextInt()
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
			if val, exists := mapS[j+1]; exists && val != int(s[j]-'0') || !exists && int(s[j]-'0') != 0 {
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

func (m *Main) gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return m.gcd(b, a%b)
}

func (m *Main) lcm(a, b int64) int64 {
	return a * b / m.gcd(a, b)
}

func (m *Main) inv(a int64) int64 {
	return m.pow(a, MOD-2)
}

func (m *Main) pow(a, r int64) int64 {
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

func (m *Main) modFact(n int64) int64 {
	if n == 0 {
		return 1
	}
	return n * m.modFact(n-1) % MOD
}

func (m *Main) fact(n int64) int64 {
	if n == 0 {
		return 1
	}
	return n * m.fact(n-1)
}

func (m *Main) initCOMB() {
	m.fac[0], m.fac[1] = 1, 1
	m.inv[1] = 1
	m.finv[0], m.finv[1] = 1, 1
	for i := 2; i < SIZE; i++ {
		m.fac[i] = m.fac[i-1] * int64(i) % MOD
		m.inv[i] = MOD - m.inv[MOD%int64(i)]*int64(MOD/int64(i))%MOD
		m.finv[i] = m.finv[i-1] * m.inv[i] % MOD
	}
}

func (m *Main) modComb(n, r int) int64 {
	if n < r || n < 0 || r < 0 {
		return 0
	}
	return m.fac[n] * m.finv[r] % MOD * m.finv[n-r] % MOD
}

func (m *Main) comb(n, r int64) int64 {
	num := int64(1)
	for i := int64(1); i <= r; i++ {
		num = num * (n-i+1) / i
	}
	return num
}

func (m *Main) isPrime(a int64) bool {
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

func (m *Main) nextPermutation(s string) string {
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
	subList := list[L : R+1]
	for i, j := 0, len(subList)-1; i < j; i, j = i+1, j-1 {
		subList[i], subList[j] = subList[j], subList[i]
	}

	return strings.Join(list, "")
}

func (m *Main) nextPermutationInt(a []int64) bool {
	for i := len(a) - 1; i > 0; i-- {
		if a[i-1] < a[i] {
			swapIndex := m.find(a[i-1], a, i, len(a)-1)
			a[swapIndex], a[i-1] = a[i-1], a[swapIndex]
			for j, k := i, len(a)-1; j < k; j, k = j+1, k-1 {
				a[j], a[k] = a[k], a[j]
			}
			return true
		}
	}
	return false
}

func (m *Main) find(dest int64, a []int64, s, e int) int {
	if s == e {
		return s
	}
	m := (s + e + 1) / 2
	if a[m] <= dest {
		return m.find(dest, a, s, m-1)
	}
	return m.find(dest, a, m, e)
}

func (m *Main) elimination(a [][]int64, b []int64) {
	n := len(a)
	var f float64
	for k := 0; k < n-1; k++ {
		for i := k + 1; i < n; i++ {
			f = -float64(a[i][k]) / float64(a[k][k])
			for j := k + 1; j < n; j++ {
				a[i][j] += int64(f * float64(a[k][j]))
			}
			b[i] += int64(f * float64(b[k]))
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
	}
	return 0
}

type FastScanner struct {
	r *bufio.Reader
}

func NewFastScanner(r io.Reader) *FastScanner {
	return &FastScanner{bufio.NewReader(r)}
}

func (s *FastScanner) next() string {
	var b []byte
	for {
		if b, _, err := s.r.ReadLine(); err != nil {
			panic(err)
		} else if len(b) == 0 {
			continue
		} else {
			return string(b)
		}
	}
}

func (s *FastScanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

// End of Code
