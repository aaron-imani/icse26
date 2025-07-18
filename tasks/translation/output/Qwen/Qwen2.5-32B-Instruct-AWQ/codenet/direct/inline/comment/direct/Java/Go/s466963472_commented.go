package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func read() (int, bool) {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		input, err := strconv.Atoi(scanner.Text())
		if err != nil {
			return 0, false
		}
		return input, true
	}
	return 0, false
}

func solve(d int) int {
	ans := 0
	for i := 1; i*d < 600; i++ {
		x := i * d
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	for {
		d, ok := read()
		if !ok {
			break
		}
		fmt.Println(solve(d))
	}
}

// End of Code
