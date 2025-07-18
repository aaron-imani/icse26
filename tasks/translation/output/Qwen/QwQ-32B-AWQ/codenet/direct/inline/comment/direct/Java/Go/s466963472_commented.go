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
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for sc.Scan() {
		token := sc.Text()
		d, err := strconv.Atoi(token)
		if err != nil {
			continue
		}
		fmt.Println(solve(d))
	}
}

// End of Code
