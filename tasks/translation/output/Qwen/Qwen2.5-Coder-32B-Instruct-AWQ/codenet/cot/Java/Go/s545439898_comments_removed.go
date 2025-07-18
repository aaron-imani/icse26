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
	countStr, _ := reader.ReadString('\n')
	count, _ := strconv.Atoi(strings.TrimSpace(countStr))

	givingNumbers := make([]int, count)
	for i := 0; i < count; i++ {
		numStr, _ := reader.ReadString(' ')
		num, _ := strconv.Atoi(strings.TrimSpace(numStr))
		givingNumbers[i] = num
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
