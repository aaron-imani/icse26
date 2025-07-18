package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	balls := make([][2]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		balls[i][0] = x
		balls[i][1] = y
	}

	ans := N

	sort.Slice(balls, func(i, j int) bool { return balls[i][0] < balls[j][0] })
	solve(balls, &ans)

	swappedBalls := make([][2]int, N)
	for i := 0; i < N; i++ {
		swappedBalls[i][0] = balls[i][1]
		swappedBalls[i][1]_ = balls[i][0]
	}
	sort.Slice(swappedBalls, func(i, j int) bool { return swappedBalls[i][0] < swappedBalls[j][0] })
	solve(swappedBalls, &ans)

	fmt.Println(ans)
}

func solve(balls [][2]int, ans *int) {
	N := len(balls)
	for add := 1; add < N; add++ {
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		current := check(balls, p, q)
		if current < *ans {
			*ans = current
		}
	}
}

func check(balls [][2]int, p, q int) int {
	N := len(balls)
	taken := make([]bool, N)
	ret := 0
	for {
		added := false
		var start int
		var x, y int
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

// End of Code
