package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			fmt.Scan(&c[i][j])
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
			A := readInt()
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

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// End of Code
