package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var ans int
var N int
var balls [][2]int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	nextInt := func() int {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		return num
	}

	N = nextInt()
	ans = N
	balls = make([][2]int, N)
	for i := 0; i < N; i++ {
		x := nextInt()
		y := nextInt()
		balls[i] = [2]int{x, y}
	}

	// First solve with original coordinates
	sortSlice()
	solve()

	// Swap coordinates and sort again
	swapCoordinates()
	sortSlice()
	solve()

	fmt.Println(ans)
}

func sortSlice() {
	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
}

func swapCoordinates() {
	for i := range balls {
		balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
	}
}

func solve() {
	for add := 1; add < N; add++ {
		taken := make([]bool, N)
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1]
		current := check(p, q, taken)
		if current < ans {
			ans = current
		}
	}
}

func check(p, q int, taken []bool) int {
	ret := 0
	for {
		added := false
		var start int
		var x, y int
		for i := 0; i < N; i++ {
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
