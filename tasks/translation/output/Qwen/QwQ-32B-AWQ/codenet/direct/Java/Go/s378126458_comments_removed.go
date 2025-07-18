package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	firstLine := scanner.Text()
	var N, Q int
	fmt.Sscanf(firstLine, "%d %d", &N, &Q)
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
		var l, r int
		fmt.Sscanf(line, "%d %d", &l, &r)
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
