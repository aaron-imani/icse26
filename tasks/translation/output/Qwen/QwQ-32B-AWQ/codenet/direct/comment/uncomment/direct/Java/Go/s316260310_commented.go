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
	var nums []int
	for scanner.Scan() {
		s := scanner.Text()
		num, _ := strconv.Atoi(s)
		nums = append(nums, num)
	}
	N := nums[0]
	K := int64(nums[1])
	A := nums[2 : 2+N]

	vis := make([]bool, N)
	curr := 0
	for !vis[curr] {
		vis[curr] = true
		curr = A[curr] - 1
	}

	straight := make([]int, 0)
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = A[st] - 1
	}

	cycle := make([]int, 0)
	cycle = append(cycle, curr)
	next := A[curr] - 1
	for next != cycle[0] {
		cycle = append(cycle, next)
		next = A[next] - 1
	}

	if K < int64(len(straight)) {
		fmt.Println(straight[K] + 1)
	} else {
		remaining := K - int64(len(straight))
		idx := int(remaining) % len(cycle)
		fmt.Println(cycle[idx] + 1)
	}
}

// End of Code
