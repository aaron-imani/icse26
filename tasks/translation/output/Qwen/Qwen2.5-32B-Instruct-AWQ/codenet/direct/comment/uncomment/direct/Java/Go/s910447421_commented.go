package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var ans = 100
var balls [][2]int
var N int
var taken []bool

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	N = readInt(reader)
	ans = N
	balls = make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i][0] = readInt(reader)
		balls[i][1] = readInt(reader)
	}
	sort.Slice(balls, func(i, j int) bool { return balls[i][0] < balls[j][0] })
	solve()
	for i := range balls {
		x := balls[i][0]
		y := balls[i][1]
		balls[i][0] = y
		balls[i][1] = x
	}
	sort.Slice(balls, func(i, j int) bool { return balls[i][0] < balls[j][0] })
	solve()
	fmt.Fprintln(writer, ans)
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt(reader *bufio.Reader) int {
	str, _ := reader.ReadString('\n')
	str = str[:len(str)-1]
	num, _ := fmt.Sscanf(str, "%d", new(int))
	return num
}

// End of Code
