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
var balls [][]int
var N int
var taken []bool

func main() {
	I := FastScanner{}
	O := OutPut{}

	N = I.nextInt()
	ans = N
	balls = make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = make([]int, 2)
		balls[i][0] = I.nextInt()
		balls[i][1] = I.nextInt()
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
	O.pln(ans)
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
		x := -1
		y := -1

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

type FastScanner struct {
	r *bufio.Reader
}

func (I *FastScanner) next() string {
	if I.r == nil {
		I.r = bufio.NewReader(os.Stdin)
	}
	str, _, err := I.r.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(string(str))
}

func (I *FastScanner) nextInt() int {
	str := I.next()
	num, err := strconv.Atoi(str)
	if err != nil {
		panic(err)
	}
	return num
}

type OutPut struct{}

func (O *OutPut) pln(x interface{}) {
	fmt.Println(x)
}

// End of Code
