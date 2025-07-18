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
	parts := strings.Fields(firstLine)
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	shortage := make([]int, 0, M)
	for i := 0; i < M; i++ {
		scanner.Scan()
		line := scanner.Text()
		A, _ := strconv.Atoi(line)
		if N > A {
			shortage = append(shortage, N-A)
		} else {
			shortage = append(shortage, 0)
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
