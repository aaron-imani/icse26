package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	S := scanner.Text()

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

// 長さが偶数の文字列sが遇文字列かどうかを返す
func isEvenString(s string) bool {
	mid := len(s) / 2
	return s[:mid] == s[mid:]
}

// End of Code
