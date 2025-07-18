package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var nums []int64
	for scanner.Scan() {
		numStr := scanner.Text()
		num, _ := strconv.ParseInt(numStr, 10, 64)
		nums = append(nums, num)
	}
	n, a, b := nums[0], nums[1], nums[2]

	sa := a - b
	if sa < 0 {
		sa = -sa
	}
	var ans int64 = 0
	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)
		ans = min(AAA, BBB)
		sa -= 1
		ans += 1
		ans += sa / 2
	}
	fmt.Println(ans)
}

// End of Code
