package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(K int, S int) int {
	ans := 0
	for x := 0; x <= K; x++ {
		for y := 0; y <= K; y++ {
			wk := S - x - y
			if wk >= 0 && wk <= K {
				ans++
			}
		}
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	if scanner.Scan() {
		input := strings.Fields(scanner.Text())
		K, _ := strconv.Atoi(input[0])
		S, _ := strconv.Atoi(input[1])

		result := solve(K, S)
		fmt.Println(result)
	}
}
// End of Code
