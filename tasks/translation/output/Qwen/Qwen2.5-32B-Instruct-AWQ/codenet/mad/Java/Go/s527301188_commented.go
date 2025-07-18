package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		os.Exit(1)
	}
	strs := strings.Split(strings.TrimSpace(input), " ")
	nums := make([]int, len(strs))
	top := 0

	for i := 0; i < len(strs); i++ {
		switch strs[i][0] {
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
			num, err := strconv.Atoi(strs[i])
			if err != nil {
				fmt.Fprintln(os.Stderr, "Error parsing number:", err)
				os.Exit(1)
			}
			nums[top] = num
			top++
		}
		//fmt.Println(nums)
	}
	fmt.Println(nums[0])
}

// End of Code
