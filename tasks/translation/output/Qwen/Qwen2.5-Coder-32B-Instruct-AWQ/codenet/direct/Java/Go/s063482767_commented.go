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
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	nums := make([]int, n)
	sc.Scan()
	input := strings.Fields(sc.Text())
	for i := 0; i < n; i++ {
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
