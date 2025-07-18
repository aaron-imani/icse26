package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	line := scanner.Text()
	fields := strings.Fields(line)
	nums := make([]int, len(fields))
	for i, s := range fields {
		num, _ := strconv.Atoi(s)
		nums[i] = num
	}
	fmt.Println(solve(nums))
}

func solve(nums []int) int {
	max := 0
	cnt := 0
	for _, num := range nums {
		if num >= max {
			max = num
			cnt++
		}
	}
	return cnt
}

// End of Code
