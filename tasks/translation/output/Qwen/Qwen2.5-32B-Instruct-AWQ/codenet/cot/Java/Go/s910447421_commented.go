package main

import (
	"fmt"
	"sort"
)

var ans = 100
var balls [][2]int
var N int
var taken []bool

func main() {
	/*Fixate two coordinates in ordered pairs and extend same arithmetic difference for as
	 * long as possible (sort coordinates first)
	 * Make connected graphs of coordinates that can be achieved with set p and q values
	 * */
	var scanner = newScanner()
	N = scanner.nextInt()
	ans = N
	balls = make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i][0] = scanner.nextInt()
		balls[i][1] = scanner.nextInt()
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
	fmt.Println(ans)
}

func solve() {
	for add := 1; add < N; add++ {
		taken = make([]bool, N)
		p := balls[add][0] - balls[0][0]
		q := balls[add][1] - balls[0][1] //Differences
		ans = min(ans, check(p, q))
	}
}

func check(p, q int) int {
	ret := 0
	for {
		added := false
		start := 0
		x := -1
		y := -1 //Coordinates that we want next
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

func newScanner() *scanner {
	return &scanner{reader: bufio.NewReader(os.Stdin)}
}

type scanner struct {
	reader *bufio.Reader
}

func (s *scanner) nextInt() int {
	var i int
	fmt.Fscan(s.reader, &i)
	return i
}

// End of Code
