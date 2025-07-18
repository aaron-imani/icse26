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
	scanner.Scan()
	firstLine := scanner.Text()
	parts := strings.Split(firstLine, " ")
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	shortage := make([]int, M)

	for i := 0; i < M; i++ {
		scanner.Scan()
		line := scanner.Text()
		A, _ := strconv.Atoi(line)
		if N > A {
			shortage[i] = N - A
		} else {
			shortage[i] = 0
		}
	}

	sort.Ints(shortage)

	sum := 0
	for i := 0; i < M-1; i++ {
		sum += shortage[i]
	}

	fmt.Println(sum)
}

// End of Code
