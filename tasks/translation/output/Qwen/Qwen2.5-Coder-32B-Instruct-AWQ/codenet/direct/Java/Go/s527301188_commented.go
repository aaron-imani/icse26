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
	input, _ := reader.ReadString('\n')
	strs := strings.Fields(input)
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
			num, _ := strconv.Atoi(strs[i])
			nums[top] = num
			top++
		}
	}
	fmt.Println(nums[0])
}

// End of Code
