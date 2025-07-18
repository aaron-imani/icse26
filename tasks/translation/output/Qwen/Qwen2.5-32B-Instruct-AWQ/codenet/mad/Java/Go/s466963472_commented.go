package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)
var d int

func read() bool {
	if !sc.Scan() {
		return false
	}
	text := sc.Text()
	d, _ = strconv.Atoi(strings.TrimSpace(text))
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
