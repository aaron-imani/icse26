package main

import (
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	nums := make([]int, len(tokens))
	top := 0

	for _, token := range tokens {
		switch token[0] {
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
			num, _ := strconv.Atoi(token)
			nums[top] = num
			top++
		}
	}
	fmt.Println(nums[0])
}

// End of Code
