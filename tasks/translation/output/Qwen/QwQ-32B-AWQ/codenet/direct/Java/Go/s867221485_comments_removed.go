package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nStr := scanner.Text()
	N, _ := strconv.Atoi(nStr)
	scanner.Scan()
	s := scanner.Text()

	ans := 0
	sha := 0
	dot := 0
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
}

// End of Code
