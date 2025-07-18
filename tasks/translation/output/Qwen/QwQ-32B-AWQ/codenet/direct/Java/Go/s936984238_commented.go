package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for {
		nums, ok := read(sc)
		if !ok {
			break
		}
		solve(nums)
	}
}

func read(sc *bufio.Scanner) ([]int, bool) {
	if !sc.Scan() {
		return nil, false
	}
	nStr := sc.Text()
	n, err := strconv.Atoi(nStr)
	if err != nil || n == 0 {
		return nil, false
	}
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		if !sc.Scan() {
			return nil, false
		}
		numStr := sc.Text()
		num, _ := strconv.Atoi(numStr)
		nums[i] = num
	}
	return nums, true
}

func solve(nums []int) {
	sort.Ints(nums)
	n := len(nums)
	sum := 0
	for i := 1; i < n-1; i++ {
		sum += nums[i]
	}
	fmt.Println(sum / (n-2))
}

// End of Code
