package main

import (
	"fmt"
	"sort"
)

func check(points [][2]int, p, q int) int {
	taken := make([]bool, len(points))
	ret := 0
	for {
		added := false
		var start, x, y int
		for i := 0; i < len(points); i++ {
			if !taken[i] {
				added = true
				ret++
				start = i
				taken[i] = true
				x = points[i][0] + p
				y = points[i][1] + q
				break
			}
		}
		if !added {
			break
		}
		for i := start + 1; i < len(points); i++ {
			if points[i][0] == x && points[i][1] == y {
				taken[i] = true
				x += p
				y += q
			}
		}
	}
	return ret
}

func main() {
	var N int
	fmt.Scan(&N)
	points := make([][2]int, N)
	for i := 0; i < N; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		points[i][0] = x
		points[i][1] = y
	}

	ans := N

	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0]
	})

	for add := 1; add < N; add++ {
		p := points[add][0] - points[0][0]
		q := points[add][1] - points[0][1]
		current := check(points, p, q)
		if current < ans {
			ans = current
		}
	}

	swapped := make([][2]int, len(points))
	for i := range points {
		swapped[i][0] = points[i][1]
		swapped[i][1] = points[i][0]
	}

	sort.Slice(swapped, func(i, j int) bool {
		return swapped[i][0] < swapped[j][0]
	})

	for add := 1; add < N; add++ {
		p := swapped[add][0] - swapped[0][0]
		q := swapped[add][1] - swapped[0][1]
		current := check(swapped, p, q)
		if current < ans {
			ans = current
		}
	}

	fmt.Println(ans)
}

// End of Code
