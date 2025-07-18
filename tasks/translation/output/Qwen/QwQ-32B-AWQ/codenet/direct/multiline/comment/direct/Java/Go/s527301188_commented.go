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
	tokens := strings.Split(line, " ")

	nums := make([]int, len(tokens))
	top := 0

	for _, token := range tokens {
		switch firstChar := token[0]; firstChar {
		case '+', '-', '*':
			top--
			a := nums[top-1]
			b := nums[top]
			var result int
			switch firstChar {
			case '+':
				result = a + b
			case '-':
				result = a - b
			case '*':
				result = a * b
			}
			nums[top-1] = result
		default:
			num, _ := strconv.Atoi(token)
			nums[top] = num
			top++
		}
	}

	fmt.Println(nums[0])
}

// End of Code
