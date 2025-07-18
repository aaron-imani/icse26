package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	S := sc.Text()

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
	half := len(s)/2
	return s[:half] == s[half:]
}
// End of Code
