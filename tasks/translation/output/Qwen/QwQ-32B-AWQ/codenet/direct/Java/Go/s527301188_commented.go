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
	line = strings.TrimSpace(line)
	tokens := strings.Split(line, " ")

	nums := make([]int, len(tokens))
	top := 0

	for _, token := range tokens {
		if len(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*') {
			top--
			switch token[0] {
			case '+':
				nums[top-1] += nums[top]
			case '-':
				nums[top-1] -= nums[top]
			case '*':
				nums[top-1] *= nums[top]
			}
		} else {
			num, _ := strconv.Atoi(token)
			nums[top] = num
			top++
		}
	}
	println(nums[0])
}

// End of Code
