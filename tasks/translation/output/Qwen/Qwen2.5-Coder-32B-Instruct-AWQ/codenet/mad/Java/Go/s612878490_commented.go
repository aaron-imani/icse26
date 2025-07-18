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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)

	parts := strings.Split(line, " ")
	N, err := strconv.Atoi(parts[0])
	if err != nil {
		fmt.Println("Error parsing N:", err)
		return
	}
	M, err := strconv.Atoi(parts[1])
	if err != nil {
		fmt.Println("Error parsing M:", err)
		return
	}

	shortage := make([]int, M)

	for i := 0; i < M; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		A, err := strconv.Atoi(line)
		if err != nil {
			fmt.Println("Error parsing A:", err)
			return
		}
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
