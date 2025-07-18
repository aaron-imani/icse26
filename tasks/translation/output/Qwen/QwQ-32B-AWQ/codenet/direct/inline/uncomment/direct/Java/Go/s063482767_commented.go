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
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		nums[i] = num
	}
	sort.Ints(nums)
	sum := 0
	for _, num := range nums {
		sum += num
	}
	max := nums[n-1]
	if sum-2*max > 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
