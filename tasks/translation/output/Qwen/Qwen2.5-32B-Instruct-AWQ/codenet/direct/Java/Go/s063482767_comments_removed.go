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
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	nums := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		nums[i], _ = strconv.Atoi(sc.Text())
	}

	sort.Ints(nums)

	sum := 0
	for i := 0; i < n-1; i++ {
		sum += nums[i]
	}

	if nums[n-1] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// End of Code
