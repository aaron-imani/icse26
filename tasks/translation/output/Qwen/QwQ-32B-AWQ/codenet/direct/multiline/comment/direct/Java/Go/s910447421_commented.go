package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var ans int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	if !scanner.Scan() {
		fmt.Println("Error reading N")
		return
	}
	N, _ := strconv.Atoi(scanner.Text())
	ans = N
	balls := make([][2]int, N)

	for i := 0; i < N; i++ {
		if !scanner.Scan() {
			fmt.Println("Error reading coordinates")
			return
		}
		line := scanner.Text()
		parts := strings.Fields(line)
		x, _ := strconv.Atoi(parts[0])
		y, _ := strconv.Atoi(parts[1])
		balls[i][0] = x
		balls[i][1] = y
	}

	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve(balls)

	for i := range balls {
		balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
	}
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve(balls)

	fmt.Println(ans)
}

func solve(balls [][2]int) {
	N := len(balls)
	for add := 1; add < N; add++ {
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		current := check(p, q, balls)
		if current < ans {
			ans = current
		}
	}
}

func check(p, q int, balls [][2]int) int {
	taken := make([]bool, len(balls))
	ret := 0

	for {
		added := false
		var x, y int
		var start int

		for i := 0; i < len(balls); i++ {
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

		for i := start + 1; i < len(balls); i++ {
			if balls[i][0] == x && balls[i][1] == y && !taken[i] {
				taken[i] = true
				x += p
				y += q
			}
		}
	}
	return ret
}

// End of Code
