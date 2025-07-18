package main

import (
	"fmt"
	"sort"
)

var ans = 100
var balls [][2]int
var N int
var taken []bool

func main() {
	var scanner Scanner
	N = scanner.nextInt()
	ans = N
	balls = make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i][0] = scanner.nextInt()
		balls[i][1] = scanner.nextInt()
	}
	sort.Slice(balls, func(i, j int) bool { return balls[i][0] < balls[j][0] })
	solve()
	for i := 0; i < N; i++ {
		x := balls[i][0]
		y := balls[i][1]
		balls[i][0] = y
		balls[i][1] = x
	}
	sort.Slice(balls, func(i, j int) bool { return balls[i][0] < balls[j][0] })
	solve()
	fmt.Println(ans)
}

func solve() {
	for add := 1; add < N; add++ {
		taken = make([]bool, N)
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		ans = min(ans, check(p, q))
	}
}

func check(p, q int) int {
	ret := 0
	for {
		added := false
		start := 0
		x, y := -1, -1
		for i := 0; i < N; i++ {
			if !taken[i] {
				added = true
				ret++
				start = i
				taken[i] = true
				x = balls[i][0] + p
				y = balls[i][1] + q
				break
			}
		}
		if !added {
			break
		}
		for i := start + 1; i < N; i++ {
			if balls[i][0] == x && balls[i][1] == y {
				taken[i] = true
				x += p
				y += q
			}
		}
	}
	return ret
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func ceil(num, den int) int {
	ans := num / den
	if num%den != 0 {
		ans++
	}
	return ans
}

func gcd(a, b int) int {
	if a == 0 || b == 0 {
		return max(a, b)
	}
	return gcd(min(a, b), max(a, b)%min(a, b))
}

func fastExp(base, exp, mod int) int {
	ans := 1
	for exp > 0 {
		if exp%2 == 1 {
			ans *= base
		}
		exp /= 2
		base *= base
		base %= mod
		ans %= mod
	}
	return ans
}

func modInv(num, mod int) int {
	return fastExp(num, mod-2, mod)
}

func pop(x int) int {
	cnt := 0
	for x > 0 {
		if x%2 == 1 {
			cnt++
		}
		x /= 2
	}
	return cnt
}

type Scanner struct {
}

func (s *Scanner) nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

// End of Code
