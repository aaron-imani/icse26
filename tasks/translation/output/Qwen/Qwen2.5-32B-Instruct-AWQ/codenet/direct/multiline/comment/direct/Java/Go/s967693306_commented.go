package main

import (
	"fmt"
	"math"
	"strconv"
)

const (
	MOD = 1000000007
	SIZE = 1000000
)

var (
	fac = make([]int64, SIZE)
	inv = make([]int64, SIZE)
	finv = make([]int64, SIZE)
)

func main() {
	solve()
}

func solve() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	mapS := make(map[int]int)

	for i := 0; i < m; i++ {
		var s, c int
		fmt.Scanf("%d %d", &s, &c)
		if val, ok := mapS[s]; ok && val != c {
			fmt.Println(-1)
			return
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
			if val, ok := mapS[j+1]; ok && val != int(s[j]-'0') || !ok && int(s[j]-'0') != 0 {
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

func gcd(a, b int64) int64 { // return a and b's greatest common divisor
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 { // return a and b's least common multiple
	return a * b / gcd(a, b)
}

func inv(a int64) int64 { // return a's inverse modulo MOD
	return pow(a, MOD-2)
}

func pow(a, r int64) int64 { // return a^r modulo MOD
	sum := int64(1)
	for r > _ {
		if (r & 1) == 1 { // when the last bit is 1 in binary representation
			sum *= a
			sum %= MOD
		}
		a *= a
		a %= MOD
		r >>= 1
	}
	return sum
}

func modFact(n int64) int64 { // return n! modulo MOD
	if n == 0 {
		return 1
	}
	return n * modFact(n-1) % MOD
}

func fact(n int64) int64 { // return n!
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
		inv[i] = MOD - inv[MOD%i] * (MOD / int64(i)) % MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func modComb(n, r int) int64 { // return nCr modulo MOD (initCOMB must be called first)
	if n < r || n < 0 || r < 0 {
		return 0
	}
	return fac[n] * finv[r] % MOD * finv[n-r] % MOD
}

func comb(n, r int64) int64 { // return nCr
	num := int64(1)
	for i := int64(1); i <= r; i++ {
		num = num * (n - i + 1) / i
	}
	return num
}

func isPrime(a int64) bool { // prime check for a
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

func nextPermutation(s string) string { // return the next permutation of s
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
	min := math.MaxInt32
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
				return a[i+i] < a[j+i]
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
	} else {
		return find(dest, a, m, e)
	}
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

// End of Code
