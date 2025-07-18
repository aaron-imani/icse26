package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	count, _ := strconv.Atoi(sc.Text())

	givingNumbers := make([]int, count)

	// Read Numbers
	for i := 0; i < count; i++ {
		sc.Scan()
		givingNumbers[i], _ = strconv.Atoi(sc.Text())
	}

	// Reversing Numbers
	for i := count - 1; i >= 0; i-- {
		fmt.Print(givingNumbers[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}

	fmt.Println()
}

// End of Code
