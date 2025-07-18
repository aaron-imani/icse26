package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanln(&s)

	if len(s)%2 == 1 {
		s = s[:len(s)-1]
	} else {
		s = s[:len(s)-2]
	}

	for len(s) > 0 {
		if isEvenString(s) {
			break
		}
		s = s[:len(s)-2]
	}
	fmt.Println(len(s))
}

// 長さが偶数の文字列sが遇文字列かどうかを返す
func isEvenString(s string) bool {
	a := s[:len(s)/2]
	b := s[len(s)/2:]
	return a == b
}
// End of Code
