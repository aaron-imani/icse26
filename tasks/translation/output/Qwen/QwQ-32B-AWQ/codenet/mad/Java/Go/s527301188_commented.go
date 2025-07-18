package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tokens := strings.Split(scanner.Text(), " ")

	nums := make([]int, len(tokens))
	top := 0

	for _, s := range tokens {
		switch s[0] {
		case '+':
			top--
			nums[top-1] = nums[top-1] + nums[top]
		case '-':
			top--
			nums[top-1] = nums[top-1] - nums[top]
		case '*':
			top--
			nums[top-1] = nums[top-1] * nums[top]
		default:
			num, _ := strconv.Atoi(s)
			nums[top] = num
			top++
		}
	}
	fmt.Println(nums[0])
// End of Code
