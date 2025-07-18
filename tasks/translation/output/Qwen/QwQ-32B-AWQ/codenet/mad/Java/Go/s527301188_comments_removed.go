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
	line, _ := reader.ReadString('
')
	strs := strings.Fields(strings.TrimSpace(line)) // Use strings.Fields to split correctly

	stack := make([]int, len(strs))
	top := 0

	for _, s := range strs {
		switch s[0] {
		case '+':
			top--
			stack[top-1] = stack[top-1] + stack[top]
		case '-':
			top--
			stack[top-1] = stack[top-1] - stack[top]
		case '*':
			top--
			stack[top-1] = stack[top-1] * stack[top]
		default:
			num, _ := strconv.Atoi(s)
			stack[top] = num
			top++
		}
	}

	fmt.Println(stack[0])
// End of Code
