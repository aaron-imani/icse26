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
		y := x * x
		ans += y * d
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		text := scanner.Text()
		d, err := strconv.Atoi(text)
		if err != nil {
			break
		}
		fmt.Println(solve(d))
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
	// End of Code
