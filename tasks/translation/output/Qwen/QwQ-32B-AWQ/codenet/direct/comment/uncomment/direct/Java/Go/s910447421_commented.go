package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var N int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
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

	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve(balls, &ans)

	for i := range balls {
		balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
	}
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve(balls, &ans)

	fmt.Println(ans)
}

func solve(balls [][2]int, ans *int) {
	N := len(balls)
	for add := 1; add < N; add++ {
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		taken := make([]bool, N)
		current := check(balls, p, q, taken)
		if current < *ans {
			*ans = current
		}
	}
}

func check(balls [][2]int, p int, q int, taken []bool) int {
	ret := 0
	for {
		added := false
		var start, x, y int
		for i := 0; i < len(balls); i++ {
			if !taken[i] {
				added = true
				ret++
				taken[i] = true
				start = i
				x = balls[i][0] + p
				y = balls[i][1] + q
				break
			}
		}
		if !added {
			break
		}
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

// End of Code
