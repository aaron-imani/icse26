package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func nextInt(tokens []string, idx *int) int {
	val, _ := strconv.Atoi(tokens[*idx])
	*idx++
	return val
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var tokens []string
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		tokens = append(tokens, parts...)
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}

	var idx int
	N := nextInt(tokens, &idx)
	list := make([]int, N)
	for i := 0; i < N; i++ {
		list[i] = nextInt(tokens, &idx)
	}

	max := 0
	count := 0
	for _, num := range list {
		if num >= max {
			max = num
			count++
		}
	}
	fmt.Println(count)
}

// End of Code
