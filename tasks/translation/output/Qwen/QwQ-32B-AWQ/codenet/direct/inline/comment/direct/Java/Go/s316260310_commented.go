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
		num, _ := strconv.Atoi(scanner.Text())
		nums = append(nums, num)
	}
	n := nums[0]
	k := int64(nums[1])
	a := make([]int, n)
	copy(a, nums[2:2+n])

	visited := make([]bool, n)
	curr := 0
	for !visited[curr] {
		visited[curr] = true
		curr = a[curr] - 1
	}

	var straight []int
	st := 0
	for st != curr {
		straight = append(straight, st)
		st = a[st] - 1
	}

	var cycle []int
	current := curr
	cycle = append(cycle, current)
	current = a[current] - 1
	for current != cycle[0] {
		cycle = append(cycle, current)
		current = a[current] - 1
	}

	if k < int64(len(straight)) {
		fmt.Println(straight[int(k)]+1)
	} else {
		rem := k - int64(len(straight))
		idx := int(rem % int64(len(cycle)))
		fmt.Println(cycle[idx]+1)
	}
}

// End of Code
