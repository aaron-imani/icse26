package main

import (
	"fmt"
	"bufio"
	"os"
)

var sc = bufio.NewScanner(os.Stdin)
var d int

func read() bool {
	if !sc.Scan() {
		return false
	}
	d, _ = fmt.Sscanf(sc.Text(), "%d", &d)
	return true
}

func solve() int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	for read() {
		fmt.Println(solve())
	}
}

// End of Code
