package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	data := readAllInts()

	idx := 0
	H := data[idx]
	idx++
	W := data[idx]
	idx++

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
		for j := 0; j < 10; j++ {
			c[i][j] = data[idx]
			idx++
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
			A := data[idx]
			idx++
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	println(ans)
}

func readAllInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	var nums []int
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		for _, f := range fields {
			num, _ := strconv.Atoi(f)
			nums = append(nums, num)
		}
	}
	return nums
}

// End of Code
