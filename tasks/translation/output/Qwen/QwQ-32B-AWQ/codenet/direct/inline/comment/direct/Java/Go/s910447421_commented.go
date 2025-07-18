package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var ans int = 100
var balls [][]int
var N int

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	ans = N
	balls = make([][]int, N)
	for i := 0; i < N; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
		balls[i] = []int{x, y}
	}
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve()
	for i := 0; i < N; i++ {
		x := balls[i][0]
		y := balls[i][1]
		balls[i][0] = y
		balls[i][1] = x
	}
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve()
	fmt.Println(ans)
}

func solve() {
	for add := 1; add < N; add++ {
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		taken := make([]bool, N)
		ret := check(p, q, taken)
		if ret < ans {
			ans = ret
		}
	}
}

func check(p, q int, taken []bool) int {
	ret := 0
	for {
		added := false
		var start int
		var x, y int
	Loop:
		for i := 0; i < N; i++ {
			if !taken[i] {
				added = true
				ret++
				taken[i] = true
				start = i
				x = balls[i][0] + p
				y = balls[i][1] + q
				break Loop
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

// End of Code
