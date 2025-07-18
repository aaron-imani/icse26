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
	line := scanner.Text()
	tokens := strings.Split(line, " ")
	nums := make([]int, len(tokens))
	var top int = 0
	for _, token := range tokens {
		switch token[0] {
		case '+':
			top--
			a := nums[top-1]
			b := nums[top]
			nums[top-1] = a + b
		case '-':
			top--
			a := nums[top-1]
			b := nums[top]
			nums[top-1] = a - b
		case '*':
			top--
			a := nums[top-1]
			b := nums[top]
			nums[top-1] = a * b
		default:
			num, _ := strconv.Atoi(token)
			nums[top] = num
			top++
		}
	}
	fmt.Println(nums[0])
}

// End of Code
