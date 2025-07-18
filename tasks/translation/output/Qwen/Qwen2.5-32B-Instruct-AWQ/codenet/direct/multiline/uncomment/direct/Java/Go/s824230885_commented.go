package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var N int
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}
	list := make([]int, N)
	for i := 0; i < N; i++ {
		if scanner.Scan() {
			list[i], _ = strconv.Atoi(scanner.Text())
		}
	}

	max := 0
	output := 0
	for _, value := range list {
		if max <= value {
			max = value
			output++
		}
	}
	fmt.Println(output)
}

// End of Code
