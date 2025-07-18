package main

import (
	"fmt"
)

func main() {
	var S string
	fmt.Scanln(&S)

	if len(S)%2 == 1 {
		S = S[:len(S)-1]
	} else {
		S = S[:len(S)-2]
	}

	for len(S) > 0 {
		if isEvenString(S) {
			break
		}
		S = S[:len(S)-2]
	}
	fmt.Println(len(S))
}

func isEvenString(s string) bool {
	a := s[:len(s)/2]
	b := s[len(s)/2:]
	return a == b
}

// End of Code
