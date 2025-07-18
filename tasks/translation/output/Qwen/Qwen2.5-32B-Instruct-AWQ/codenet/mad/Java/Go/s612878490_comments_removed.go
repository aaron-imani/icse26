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
	input := scanner.Text()
	parts := strings.Fields(input)
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	shortage := make([]int, M)

	for i := 0; i < M; i++ {
		scanner.Scan()
		input := scanner.Text()
		A, _ := strconv.Atoi(strings.Fields(input)[0])
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
