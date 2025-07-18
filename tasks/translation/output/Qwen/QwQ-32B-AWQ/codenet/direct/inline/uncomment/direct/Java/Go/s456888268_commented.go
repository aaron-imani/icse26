package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	cnt := 0
	ans := 0
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c == 'S' {
			cnt++
		} else {
			if cnt > 0 {
				cnt--
				ans++
			}
		}
	}
	fmt.Println(len(s) - 2*ans)
}

// End of Code
