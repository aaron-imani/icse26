package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan() // Read the input line
	s := sc.Text()
	n := len(s)
	cnt := 0
	ans := 0
	for i := 0; i < n; i++ {
		c := s[i]
		if c == 'S' {
			cnt++
		} else if c == 'T' {
			if cnt > 0 {
				cnt--
				ans++
			}
		}
	}
	fmt.Println(n - 2*ans)
}

// End of Code
