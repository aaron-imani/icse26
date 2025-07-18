package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	solve()
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	nums := strings.Fields(scanner.Text())
	max, _ := strconv.Atoi(nums[0])
	min := max

	for i := 1; i < N; i++ {
		in, _ := strconv.Atoi(nums[i])
		if in > max {
			max = in
		}
		if in < min {
			min = in
		}
	}
	fmt.Println(max - min)
}
// End of Code
