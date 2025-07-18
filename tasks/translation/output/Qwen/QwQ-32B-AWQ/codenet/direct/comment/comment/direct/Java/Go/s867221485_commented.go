package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := fmt.Sscan(scanner.Text(), &scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	ans, sha, dot := 0, 0, 0
	first := true

	for i := 0; i < len(s); i++ {
		c := s[i]
		if c == '#' {
			first = false
			if sha <= dot {
				ans += sha
				sha, dot = 0, 0
				first = true
			}
			sha++
		} else {
			if !first {
				dot++
			}
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	}

	fmt.Println(ans + dot)
}
// End of Code
