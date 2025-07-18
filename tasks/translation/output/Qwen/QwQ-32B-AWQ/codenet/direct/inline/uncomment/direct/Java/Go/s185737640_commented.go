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
	S = S[:len(S)-1]

	if len(S)%2 != 0 {
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
	if len(s)%2 != 0 {
		return false
	}
	mid := len(s) / 2
	return s[:mid] == s[mid:]
}

// End of Code
