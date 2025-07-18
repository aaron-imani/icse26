package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)
var d int

func read() bool {
	sc.Scan()
	if sc.Err() != nil {
		return false
	}
	line := sc.Text()
	if len(line) == 0 {
		return false
	}
	var err error
	d, err = strconv.Atoi(strings.TrimSpace(line))
	if err != nil {
		return false
	}
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
