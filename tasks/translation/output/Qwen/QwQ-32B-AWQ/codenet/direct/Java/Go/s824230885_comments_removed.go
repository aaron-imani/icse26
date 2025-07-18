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
		fmt.Fprintln(os.Stderr, "Reading input:", err)
		os.Exit(1)
	}

	N, _ := strconv.Atoi(lines[0])
	parts := strings.Fields(lines[1])
	list := make([]int, N)
	for i, s := range parts {
		num, _ := strconv.Atoi(s)
		list[i] = num
	}

	max := 0
	count := 0
	for _, num := range list {
		if num >= max {
			count++
			max = num
		}
	}
	fmt.Println(count)
}

// End of Code
