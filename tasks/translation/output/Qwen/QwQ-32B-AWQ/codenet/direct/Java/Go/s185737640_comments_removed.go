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
	S = strings.TrimRight(S, "\r\n")

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
	half := len(s) / 2
	return s[:half] == s[half:]
}

// End of Code
