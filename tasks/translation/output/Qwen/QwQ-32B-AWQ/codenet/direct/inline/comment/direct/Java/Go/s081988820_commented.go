package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
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
	index := 0
	H := nums[index]
	index++
	W := nums[index]
	index++

	c := make([][]int, 10)
	for i := 0; i < 10; i++ {
		c[i] = make([]int, 10)
		for j := 0; j < 10; j++ {
			c[i][j] = nums[index]
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
				temp := c[i][j] + min[j]
				if temp < min[i] {
					min[i] = temp
				}
			}
		}
	}

	ans := 0
	for k := 0; k < H*W; k++ {
		A := nums[index]
		index++
		if A >= 0 {
			ans += min[A]
		}
	}
	fmt.Println(ans)
}

// End of Code
