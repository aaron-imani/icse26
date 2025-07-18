package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	pre := make([]int, N+1)
	for i := 1; i < N; i++ {
		if s[i-1] == 'A' && s[i] == 'C' {
			pre[i] = 1
		}
	}
	// Build prefix sum
	for i := 1; i < N; i++ {
		pre[i] += pre[i-1]
	}
	for Q > 0 {
		Q--
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
