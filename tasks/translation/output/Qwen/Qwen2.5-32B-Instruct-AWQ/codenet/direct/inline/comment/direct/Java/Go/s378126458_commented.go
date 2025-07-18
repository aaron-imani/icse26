package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	input := strings.Fields(sc.Text())
	N, _ := strconv.Atoi(input[0])
	Q, _ := strconv.Atoi(input[1])
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

	for Q > 0 {
		sc.Scan()
		input := strings.Fields(sc.Text())
		l, _ := strconv.Atoi(input[0])
		r, _ := strconv.Atoi(input[1])
		r--
		fmt.Println(pre[r] - pre[l-1])
		Q--
	}
}
// End of Code
