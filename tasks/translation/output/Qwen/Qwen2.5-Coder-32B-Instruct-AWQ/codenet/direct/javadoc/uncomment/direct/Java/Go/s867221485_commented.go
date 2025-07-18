package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	var s string
	fmt.Scan(&s)

	flag := false
	ans := 0
	sha := 0
	dot := 0
	first := true

	for i := 0; i < N; i++ {
		if s[i] == '#' {
			first = false
			if sha <= dot {
				ans += sha
				sha = 0
				dot = 0
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
