package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var d int

func read() bool {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		input := strings.Fields(scanner.Text())
		if len(input) > 0 {
			if val, err := strconv.Atoi(input[0]); err == nil {
				d = val
				return true
			}
		}
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
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		if !read() {
			break
		}
		fmt.Println(solve())
	}
} // End of Code
