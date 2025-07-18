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
	input := strings.Fields(scanner.Text())
	N, _ := strconv.Atoi(input[0])
	Q, _ := strconv.Atoi(input[1])
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

	for Q > 0 {
		scanner.Scan()
		query := strings.Fields(scanner.Text())
		l, _ := strconv.Atoi(query[0])
		r, _ := strconv.Atoi(query[1])
		r--
		fmt.Println(pre[r] - pre[l-1])
		Q--
	}
}
// End of Code
