package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	solve()
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	max, _ := strconv.Atoi(scanner.Text())
	min := max

	for i := 1; i < N; i++ {
		scanner.Scan()
		in, _ := strconv.Atoi(scanner.Text())
		if in > max {
			max = in
		}
		if in < min {
			min = in
		}
	}
	fmt.Println(max - min)
}

// End of Code
