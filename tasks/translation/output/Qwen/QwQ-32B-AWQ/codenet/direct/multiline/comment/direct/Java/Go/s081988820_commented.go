package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		tokens = append(tokens, num)
	}
	H := tokens[0]
	W := tokens[1]
	index := 2

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			c[i][j] = tokens[index]
			index++
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				if min[i] > c[i][j]+min[j] {
					min[i] = c[i][j] + min[j]
				}
			}
		}
	}

	ans := 0
	for h := 0; h < H; h++ {
		for w := 0; w < W; w++ {
			A := tokens[index]
			index++
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}

// End of Code
