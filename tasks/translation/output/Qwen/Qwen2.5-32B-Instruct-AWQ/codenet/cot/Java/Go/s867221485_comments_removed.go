package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	var s string
	fmt.Scanf("%s", &s)

	var flag bool = false
	var ans int = 0
	var hen int = 0
	var sha int = 0
	var dot int = 0
	var temp int = 0
	var first bool = true

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
			dot++
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	}

	fmt.Println(ans + dot) // End of Code
