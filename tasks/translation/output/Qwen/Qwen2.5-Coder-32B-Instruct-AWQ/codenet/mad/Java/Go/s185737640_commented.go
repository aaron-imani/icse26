package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)

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

// isEvenString checks if a string of even length is an even string.
func isEvenString(s string) bool {
	a := s[:len(s)/2]
	b := s[len(s)/2:]
	return a == b
}

// End of Code
