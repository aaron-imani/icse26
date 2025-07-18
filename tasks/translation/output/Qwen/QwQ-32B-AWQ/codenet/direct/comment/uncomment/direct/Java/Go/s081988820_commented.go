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
	var nums []int
	for sc.Scan() {
		num, _ := strconv.Atoi(sc.Text())
		nums = append(nums, num)
	}
	H := nums[0]
	W := nums[1]
	idx := 2
	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
		for j := range c[i] {
			c[i][j] = nums[idx]
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
	for ; idx < len(nums); idx++ {
		A := nums[idx]
		if A >= 0 {
			ans += min[A]
		}
	}
	fmt.Println(ans)
}

// End of Code
