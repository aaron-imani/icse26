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
	I := NewFastScanner()
	O := NewOutPut()
	N = I.NextInt()
	ans = N
	balls = make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = make([]int, 2)
		balls[i][0] = I.NextInt()
		balls[i][1] = I.NextInt()
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

func NewFastScanner() *FastScanner {
	r := bufio.NewReader(os.Stdin)
	return &FastScanner{r: r}
}

func (f *FastScanner) Next() string {
	var s string
	for {
		line, _, err := f.r.ReadLine()
		if err != nil {
			panic(err)
		}
		s += string(line)
		if !strings.HasSuffix(s, "\n") {
			continue
		}
		break
	}
	return strings.TrimSpace(s)
}

func (f *FastScanner) NextInt() int {
	i, _ := strconv.Atoi(f.Next())
	return i
}

type OutPut struct {
	w *bufio.Writer
}

func NewOutPut() *OutPut {
	w := bufio.NewWriter(os.Stdout)
	return &OutPut{w: w}
}

func (o *OutPut) pln(x interface{}) {
	fmt.Fprintln(o.w, x)
	o.w.Flush()
}

// End of Code
