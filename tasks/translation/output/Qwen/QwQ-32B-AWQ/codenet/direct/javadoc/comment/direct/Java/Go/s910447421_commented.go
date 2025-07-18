package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var ans int
var balls [][2]int
var N int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	ans = N
	balls = make([][2]int, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		balls[i][0] = x
		balls[i][1] = y
	}

	sortBalls()

	solve()

	// Swap x and y
	for i := range balls {
		tmp := balls[i][0]
		balls[i][0] = balls[i][1]
		balls[i][1] = tmp
	}

	sortBalls()

	solve()

	fmt.Println(ans)
}

func sortBalls() {
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
}

func solve() {
	for add := 1; add < N; add++ {
		p := balls[add][0] - balls[0][0]
		q := balls[add][1]. - balls[0][1]
		taken := make([]bool, N)
		cnt := check(p, q, balls, taken)
		ans = min(ans, cnt)
	}
}

func check(p, q int, balls [][2]int, taken []bool) int {
	ret := 0
Loop:
	for {
		var added bool
		var start, x, y int
		for i := 0; i < len(balls); i++ {
			if !taken[i] {
				ret++
				taken[i] = true
				start = i
				x = balls[i][0] + p
				y = balls[i][1] + q
				added = true
				break // Break the inner loop
			}
		}
		if !added {
			break // Exit the outer loop
		}

		// Check subsequent points
		for i := start + 1; i < len(balls); i++ {
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

// End of Code
