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
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	nums := make([]int, len(tokens))
	var top int
	top = 0

	for _, token := range tokens {
		switch token[0] {
		case '+', '-', '*':
			top--
			switch token[0] {
			case '+':
				nums[top-1] += nums[top]
			case '-':
				nums[top-1] -= nums[top]
			case '*':
				nums[top-1] *= nums[top]
			}
		default:
			num, _ := strconv.Atoi(token)
			nums[top] = num
			top++
		}
	}
	fmt.Println(nums[0])
}

// End of Code
