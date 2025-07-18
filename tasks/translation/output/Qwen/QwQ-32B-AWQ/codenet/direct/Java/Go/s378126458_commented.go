package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	firstLine := scanner.Text()
	fields := strings.Fields(firstLine)
	N, _ := strconv.Atoi(fields[0])
	Q, _ := strconv.Atoi(fields[1])

	scanner.Scan()
	s := scanner.Text()

	pre := make([]int, N+1)

	for i := 1; i < N; i++ {
		if s[i-1] == 'A' && s[i] == 'C' {
			pre[i] = 1
		}
	}

	for i := 1; i < N; i++ {
		pre[i] += pre[i-1]
	}

	for q := 0; q < Q; q++ {
		scanner.Scan()
		line := scanner.Text()
		fields := strings.Fields(line)
		l, _ := strconv.Atoi(fields[0])
		r, _ := strconv.Atoi(fields[1])
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
