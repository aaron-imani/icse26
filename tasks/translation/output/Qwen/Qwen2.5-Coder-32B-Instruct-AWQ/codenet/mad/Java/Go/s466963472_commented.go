package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

var d int

func read() bool {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		var err error
		d, err = strconv.Atoi(scanner.Text())
		return err == nil
	}
	return false
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
