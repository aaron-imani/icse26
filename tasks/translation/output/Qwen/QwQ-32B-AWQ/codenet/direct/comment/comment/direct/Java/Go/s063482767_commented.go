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
	var tokens []string
	for sc.Scan() {
		tokens = append(tokens, sc.Text())
	}
	n, _ := strconv.Atoi(tokens[0])
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(tokens[1+i])
		nums[i] = num
	}
	sort.Ints(nums)
	sum := 0
	for _, v := range nums[:len(nums)-1] {
		sum += v
	}
	if nums[len(nums)-1] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
