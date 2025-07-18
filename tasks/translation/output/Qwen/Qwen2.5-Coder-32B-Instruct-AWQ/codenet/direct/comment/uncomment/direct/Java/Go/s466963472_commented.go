package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func read() (int, bool) {
	sc.Scan()
	if err := sc.Err(); err != nil {
		return 0, false
	}
	line := sc.Text()
	if len(line) == 0 {
		return 0, false
	}
	d, err := strconv.Atoi(strings.TrimSpace(line))
	if err != nil {
		return 0, false
	}
	return d, true
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
	sc.Split(bufio.ScanLines)
	for {
		d, ok := read()
		if !ok {
			break
		}
		fmt.Println(solve(d))
	}
}
// End of Code
