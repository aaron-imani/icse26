package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var ans int = 100
var balls [][]int
var N int
var taken []bool

func main() {
	// Fixate two coordinates in ordered pairs and extend same arithmetic difference for as
	// long as possible (sort coordinates first)
	// Make connected graphs of coordinates that can be achieved with set p and q values
	I := FastScanner{bufio.NewScanner(os.Stdin)}
	O := OutPut{bufio.NewWriter(os.Stdout)}
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
	O.w.Flush()
}

func solve() {
	for add := 1; add < N; add++ {
		taken = make([]bool, N)
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1] // Differences
		ans = min(ans, check(p, q))
	}
}

func check(p, q int) int {
	ret := 0
	for {
		added := false
		start := 0
		x := -1
		y := -1 // Coordinates that we want next
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
	scanner *bufio.Scanner
}

func (fs *FastScanner) next() string {
	if !fs.scanner.Scan() {
		panic("No more input")
	}
	return fs.scanner.Text()
}

func (fs *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(fs.next())
	return i
}

type OutPut struct {
	w *bufio.Writer
}

func (o *OutPut) pln(x int) {
	fmt.Fprintln(o.w, x)
}

// End of Code
