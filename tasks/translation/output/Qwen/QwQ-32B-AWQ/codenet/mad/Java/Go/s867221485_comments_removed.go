package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var N int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &N)
	scanner.Scan()
	s := scanner.Text()

	var ans, sha, dot int
	first := true

	for i := 0; i < len(s); i++ {
		c := s[i]
		if c == '#' {
			first = false
			if sha <= dot {
				ans += sha
				sha = 0
				dot = 0
				first = true
			}
			sha++
		} else {
			dot++
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	}

	fmt.Println(ans + dot)
// End of Code
