package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	H, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	W, _ := strconv.Atoi(sc.Text())
	sc.Scan()

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			sc.Scan()
			c[i][j], _ = strconv.Atoi(sc.Text())
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				min[i] = minInt(min[i], c[i][j]+min[j])
			}
		}
	}

	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			sc.Scan()
			A, _ := strconv.Atoi(sc.Text())
			if A >= 0 {
				ans += min[A]
			}
		}
	}

	fmt.Println(ans)
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	solve()
}
// End of Code
