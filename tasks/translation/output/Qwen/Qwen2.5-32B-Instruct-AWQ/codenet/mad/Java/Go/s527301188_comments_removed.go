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
		fmt.Println("Error reading input:", err)
		return
	}
	strs := strings.Fields(strings.TrimSpace(input))
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
				fmt.Println("Error parsing integer:", err)
				return
			}
			nums[top] = num
			top++
		}
	}

	fmt.Println(nums[0])
} // End of Code
