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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	count, _ := strconv.Atoi(input)

	var givingNumbers []int
	for i := 0; i < count; i++ {
		numberStr, _ := reader.ReadString('\n')
		numberStr = strings.TrimSpace(numberStr)
		number, _ := strconv.Atoi(numberStr)
		givingNumbers = append(givingNumbers, number)
	}

	for i := count - 1; i >= 0; i-- {
		fmt.Print(givingNumbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}

	fmt.Println()
}
// End of Code
