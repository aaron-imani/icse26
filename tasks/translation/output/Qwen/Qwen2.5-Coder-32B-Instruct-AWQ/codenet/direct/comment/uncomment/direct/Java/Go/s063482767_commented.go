package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	nums := make([]int, n)
	scanner.Scan()
	input := strings.Fields(scanner.Text())
	for i := range nums {
		nums[i], _ = strconv.Atoi(input[i])
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
