package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var N, Q int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	Q, _ = strconv.Atoi(sc.Text())
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
		l, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		r, _ := strconv.Atoi(sc.Text())
		r--
		fmt.Println(pre[r] - pre[l-1])
	}
}

// End of Code
