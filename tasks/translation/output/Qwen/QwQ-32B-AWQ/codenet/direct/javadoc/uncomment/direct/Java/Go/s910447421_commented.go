package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

var ans int
var balls [][]int
var N int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	N = nextInt(scanner)
	ans = N
	balls = make([][]int, N)
	for i := 0; i < N; i++ {
		x := nextInt(scanner)
		y := nextInt(scanner)
		balls[i] = []int{x, y}
	}

	sort.Slice(balls, func(i, j int) bool {
		return balls[i][0] < balls[j][0]
	})
	solve()

	for i := range balls {
		balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
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
		current := check(p, q)
		if current < ans {
			ans = current
		}
	}
}

func check(p, q int) int {
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

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// End of Code
