package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func solve(s []byte) {
	n := len(s)
	cnt := 0
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == 'S' {
			cnt++
		} else {
			if cnt > 0 {
				ans++
				cnt--
			}
		}
	}
	fmt.Println(n - 2*ans)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the trailing newline character
	solve([]byte(s))
}

// End of Code
