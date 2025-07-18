package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scores, ok := read(scanner)
		if !ok {
			break
		}
		solve(scores)
	}
}

func read(scanner *bufio.Scanner) ([]int, bool) {
	if !scanner.Scan() {
		return nil, false
	}
	line := scanner.Text()
	parts := strings.Fields(line)
	if len(parts) == 0 {
		return nil, false
	}
	numberStr := parts[0]
	number, err := strconv.Atoi(numberStr)
	if err != nil {
		panic(err)
	}
	if number == 0 {
		return nil, false
	}
	if len(parts) != number+1 {
		panic("invalid input")
	}
	scores := make([]int, number)
	for i := 0; i < number; i++ {
		numStr := parts[i+1]
		num, _ := strconv.Atoi(numStr)
		scores[i] = num
	}
	return scores, true
}

func solve(scores []int) {
	sort.Ints(scores)
	sum := 0
	n := len(scores)
	for i := 1; i < n-1; i++ {
		sum += scores[i]
	}
	fmt.Println(sum / (n-2))
}

// End of Code
