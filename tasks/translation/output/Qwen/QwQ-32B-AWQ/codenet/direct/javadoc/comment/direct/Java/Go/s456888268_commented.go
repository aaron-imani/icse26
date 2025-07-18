package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	solve(s)
}

func solve(s string) {
	ans := 0
	cnt := 0
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c == 'S' {
			cnt++
		} else if c == 'N' {
			if cnt > 0 {
				ans++
				cnt--
			}
		}
	}
	fmt.Println(len(s) - 2*ans)
}

// End of Code
