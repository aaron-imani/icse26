package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

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
	if err := scanner.Err(); err != nil {
		panic(err)
	}
	return nums
}

func main() {
	nums := readAllInts()
	H := nums[0]
	W := nums[1]
	index := 2

	c := make([][]int, 10)
	for i := range c {
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
				if c[i][j]+min[j] < min[i] {
					min[i] = c[i][j] + min[j]
				}
			}
		}
	}

	ans := 0
	for ; index < len(nums); {
		A := nums[index]
		index++
		if A >= 0 {
			ans += min[A]
		}
	}
	fmt.Println(ans)
}

// End of Code
