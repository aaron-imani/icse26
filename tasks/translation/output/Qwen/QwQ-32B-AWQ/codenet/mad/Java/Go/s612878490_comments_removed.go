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
		shortage[i] = max(0, N-A)
	}

	sort.Ints(shortage)

	ans := 0
	for i := 0; i < M-1; i++ {
		ans += shortage[i]
	}

	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
