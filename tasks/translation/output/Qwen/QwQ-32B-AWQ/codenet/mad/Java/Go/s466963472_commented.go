package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(d int) int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		ans += x * x * d
	}
	return ans
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for sc.Scan() {
		dStr := sc.Text()
		d, _ := strconv.Atoi(dStr)
		fmt.Println(solve(d))
	}
	if err := sc.Err(); err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
	}
}

// End of Code
