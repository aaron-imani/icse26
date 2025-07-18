package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(s string) int {
	cnt := 0
	ans := 0
	for _, c := range s {
		if c == 'S' {
			cnt++
		} else {
			if cnt > 0 {
				ans++
				cnt--
			}
		}
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	ans := solve(s)
	fmt.Println(len(s) - 2*ans)
}

// End of Code
