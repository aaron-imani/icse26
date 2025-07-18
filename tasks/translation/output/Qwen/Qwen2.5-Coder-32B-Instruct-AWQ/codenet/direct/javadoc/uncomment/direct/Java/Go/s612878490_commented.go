package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)

	parts := strings.Split(line, " ")
	N, _ := strconv.Atoi(parts[0])
	M, _ := strconv.Atoi(parts[1])

	shortage := make([]int, M)

	for i := 0; i < M; i++ {
		line, _ = reader.ReadString('\n')
		line = strings.TrimSpace(line)
		A, _ := strconv.Atoi(line)
		if N > A {
			shortage[i] = N - A
		} else {
			shortage[i] = 0
		}
	}

	for i := 0; i < M-1; i++ {
		for j := i + 1; j < M; j++ {
			if shortage[i] > shortage[j] {
				shortage[i], shortage[j] = shortage[j], shortage[i]
			}
		}
	}

	ans := 0
	for i := 0; i < M-1; i++ {
		ans += shortage[i]
	}

	fmt.Println(ans)
}

// End of Code
