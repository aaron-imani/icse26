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
	strs := strings.Fields(line)

	var stack []int
	for _, str := range strs {
		switch str[0] {
		case '+', '-', '*':
			b := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			a := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			var result int
			switch str[蕹
			case '+':
				result = a + b
			case '-':
				result = a - b
			case '*':
				result = a * b
			}
			stack = append(stack, result)
		default:
			num, _ := strconv.Atoi(str)
			stack = append(stack, num)
		}
	}
	println(stack[0])
}

// End of Code
