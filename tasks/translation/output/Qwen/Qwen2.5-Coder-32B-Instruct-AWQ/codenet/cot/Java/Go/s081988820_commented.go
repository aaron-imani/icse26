package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	main := Main{}
	main.solve()
}

type Main struct{}

func (m *Main) solve() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	line := sc.Text()
	split := strings.Split(line, " ")
	H, _ := strconv.Atoi(split[0])
	W, _ := strconv.Atoi(split[1])

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
		sc.Scan()
		line = sc.Text()
		split = strings.Split(line, " ")
		for j := range c[i] {
			c[i][j], _ = strconv.Atoi(split[j])
		}
	}

	min := make([]int, 10)
	for i := range min {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				if c[i][j]+min[j] < min[i] {
					min[i] = c[i][j] + min[j]
				}
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

// End of Code
