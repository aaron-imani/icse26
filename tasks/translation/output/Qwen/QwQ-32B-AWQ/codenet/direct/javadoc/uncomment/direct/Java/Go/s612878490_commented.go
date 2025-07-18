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
	reader := bufio.NewReader(os.Stdin)
	line1, _ := reader.ReadString('\n')
	line1 = strings.TrimSpace(line1)
	parts := strings.Split(line1, " ")
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	shortage := make([]int, M)
	for i := 0; i < M; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		A, _ := strconv.Atoi(line)
		if N > A {
			shortage[i] = N - A
		} else {
			shortage[i] = 0
		}
	}

	sort.Ints(shortage)

	sum := 0
	for i := 0; i < len(shortage)-1; i++ {
		sum += shortage[i]
	}

	fmt.Println(sum)
}

// End of Code
