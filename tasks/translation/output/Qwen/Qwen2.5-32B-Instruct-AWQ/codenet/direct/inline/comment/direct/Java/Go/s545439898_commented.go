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
	count, _ := strconv.Atoi(strings.TrimSpace(input))

	var givingNumbers []int
	for i := 0; i < count; i++ {
		numberStr, _ := reader.ReadString('\n')
		number, _ := strconv.Atoi(strings.TrimSpace(numberStr))
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
