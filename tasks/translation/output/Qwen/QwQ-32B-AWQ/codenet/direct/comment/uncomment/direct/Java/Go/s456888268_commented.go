package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(s string) int {
	cnt := 0
	ans := 0
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'S':
			cnt++
		case 'T':
			if cnt > 0 {
				ans++
				cnt--
			}
		}
	}
	return len(s) - 2*ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	fmt.Println(solve(input))
}
// End of Code
