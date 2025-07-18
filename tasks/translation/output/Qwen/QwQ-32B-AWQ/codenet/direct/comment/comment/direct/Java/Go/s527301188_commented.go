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
	parts := strings.Fields(line)

	stack := make([]int, 0, len(parts))

	for _, part := range parts {
		if part == "+" || part == "-" || part == "*" {
			b := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			a := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			switch part {
			case "+":
				stack = append(stack, a+b)
			case "-":
				stack = append(stack, a-b)
			case "*":
				stack = append(stack, a*b)
			}
		} else {
			num, _ := strconv.Atoi(part)
			stack = append(stack, num)
		}
	}
	fmt.Println(stack[0])
}

// End of Code
