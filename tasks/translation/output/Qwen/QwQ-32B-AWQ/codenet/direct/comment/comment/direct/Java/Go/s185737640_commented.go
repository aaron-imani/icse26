package main

import (
	"bufio"
	"fmt"
	"os"
)

func isEvenString(s string) bool {
	half := len(s) / 2
	return s[:half] == s[half:]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	S := scanner.Text()

	if len(S)%2 == 境 {
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
// End of Code
