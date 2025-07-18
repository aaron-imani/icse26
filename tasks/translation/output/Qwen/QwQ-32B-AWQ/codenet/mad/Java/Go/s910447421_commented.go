package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

var ans int = 100
var balls [][2]int
var N int
var taken []bool

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
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
		var start int
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		tokens = append(tokens, num)
	}
	N = tokens[0]
	tokens = tokens[1:]
	balls = make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i][0] = tokens[2*i]
		balls[i][1] = tokens[2*i+1]
	}
	ans = N
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
// End of Code
