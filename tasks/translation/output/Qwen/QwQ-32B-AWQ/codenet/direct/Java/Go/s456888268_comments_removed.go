package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanln(&s)
	fmt.Println(compute(s))
}

func compute(s string) int {
	n := len(s)
	cnt := 0
	ans := 0
	for i := 0; i < n; i++ {
		c := s[i]
		if c == 'S' {
			cnt++
		} else {
			if cnt > 0 {
				cnt--
				ans++
			}
		}
	}
	return n - 2*ans
// End of Code
