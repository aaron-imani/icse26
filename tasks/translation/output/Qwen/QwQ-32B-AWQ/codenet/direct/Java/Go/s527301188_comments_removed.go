package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")

	nums := make([]int, len(tokens))
	top := 0

	for _, s := range tokens {
		switch s[0] {
		case '+':
			top--
			nums[top-1] = nums[top-1] + nums[top]
		case '-':
			top--
			nums[top-1] = nums[top-_1] - nums[top]
		case '*':
			top--
			nums[top-1] = nums[top-1] * nums[top]
		default:
			num, _ := strconv.Atoi(s)
			nums[top] = num
			top++
		}
	}

	println(nums[0])
}

// End of Code
