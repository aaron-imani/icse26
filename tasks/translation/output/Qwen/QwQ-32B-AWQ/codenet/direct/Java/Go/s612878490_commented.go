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
	fields := strings.Fields(firstLine)
	N, _ := strconv.Atoi(fields[0])
	M, _ := strconv.Atoi(fields[1])

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

	ans := 0
	for i := 0; i < M-1; i++ {
		ans += shortage[i]
	}

	fmt.Println(ans)
}

// End of Code
