package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var tokens []int
	for sc.Scan() {
		num, _ := strconv.Atoi(sc.Text())
		tokens = append(tokens, num)
	}
	index := 0
	H := tokens[index]
	index++
	W := tokens[index]
	index++

	c := make([][]int, 10)
	for i := 0; i < 10; i++ {
		c[i] = make([]int, 10)
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
				newVal := c[i][j] + min[j]
				if newVal < min[i] {
					min[i] = newVal
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
