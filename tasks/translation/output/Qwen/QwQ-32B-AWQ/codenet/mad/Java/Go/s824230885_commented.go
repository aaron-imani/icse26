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
	var lines []string
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "Reading from stdin failed:", err)
		os.Exit(1)
	}

	N, _ := strconv.Atoi(lines[0])
	parts := strings.Fields(lines[1])
	if len(parts) < N {
		fmt.Fprintln(os.Stderr, "Insufficient elements in input array.")
		os.Exit(1)
	}
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		num, _ := strconv.Atoi(parts[i])
		arr[i] = num
	}

	max := 0
	count := 0
	for _, num := range arr {
		if num >= max {
			max = num
			count++
		}
	}
	fmt.Println(count)
}

// End of Code
