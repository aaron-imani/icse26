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

	strs := strings.Fields(input)
	nums := make([]int, len(strs))
	top := 0

	for i := 0; i < len(strs); i++ {
		switch strs[i][0] {
		case '+':
			if top < 2 {
				fmt.Println("Invalid operation: not enough operands for +")
				return
			}
			top--
			nums[top-1] = nums[top-1] + nums[top]
		case '-':
			if top < 2 {
				fmt.Println("Invalid operation: not enough operands for -")
				return
			}
			top--
			nums[top-1] = nums[top-1] - nums[top]
		case '*':
			if top < 2 {
				fmt.Println("Invalid operation: not enough operands for *")
				return
			}
			top--
			nums[top-1] = nums[top-1] * nums[top]
		default:
			num, err := strconv.Atoi(strs[i])
			if err != nil {
				fmt.Println("Error converting string to int:", err)
				return
			}
			nums[top] = num
			top++
		}
	}

	if top != 1 {
		fmt.Println("Invalid input: too many or too few operands")
		return
	}

	fmt.Println(nums[0])
}

// End of Code
