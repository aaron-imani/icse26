package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	line1 := sc.Text()
	var N, Q int
	fmt.Sscanf(line1, "%d %d", &N, &Q)
	sc.Scan()
	s := sc.Text()
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
		sc.Scan()
		line := sc.Text()
		var l, r int
		fmt.Sscanf(line, "%d %d", &l, &r)
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
