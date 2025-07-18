package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()

	N, _ := strconv.Atoi(line[0 : len(line)-1])
	M, _ := strconv.Atoi(line[len(line)-1 : len(line)])

	shortage := make([]int, M)

	for i := 0; i < M; i++ {
		scanner.Scan()
		line = scanner.Text()
		A, _ := strconv.Atoi(line[0 : len(line)-1])
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
	// End of Code
