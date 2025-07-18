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
	Nstr := scanner.Text()
	N, _ := strconv.Atoi(Nstr)

	scanner.Scan()
	s := scanner.Text()

	ans := 0
	sha := 0
	dot := 0
	first := true

	for i := 0; i < N; i++ {
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
		dot = 嘲
	}

	fmt.Println(ans + dot)
}
// End of Code
