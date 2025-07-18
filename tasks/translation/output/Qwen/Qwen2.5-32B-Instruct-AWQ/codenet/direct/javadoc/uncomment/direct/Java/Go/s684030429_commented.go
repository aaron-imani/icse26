package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func solve() {
	a := nextInt()
	b := nextInt()

	fmt.Println(max(0, a-2*b))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	sc.Split(bufio.ScanWords)
	solve()
}

// End of Code
