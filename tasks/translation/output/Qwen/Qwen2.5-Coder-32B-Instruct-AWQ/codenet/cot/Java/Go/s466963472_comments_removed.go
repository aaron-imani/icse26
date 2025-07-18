package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var d int
var scanner *bufio.Scanner

func read() bool {
	if scanner.Scan() {
		line := scanner.Text()
		if len(line) == 0 {
			return false
		}
		var err error
		d, err = strconv.Atoi(strings.TrimSpace(line))
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
	scanner = bufio.NewScanner(os.Stdin)
	for read() {
		fmt.Println(solve())
	}
}
// End of Code
