package main

import (
	"fmt"
)

func solve(s string) {
	ans := 0
	cnt := 0
	for _, c := range s {
		if c == 'S' {
			cnt++
		} else {
			if cnt == 0 {
				continue
			}
			ans++
			cnt--
		}
	}
	fmt.Println(len(s) - 2*ans)
}

func main() {
	var s string
	fmt.Scanln(&s)
	solve(s)
}
// End of Code
