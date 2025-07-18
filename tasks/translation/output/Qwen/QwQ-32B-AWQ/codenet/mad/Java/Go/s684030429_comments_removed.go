package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var tokens []string
var tokenIndex int = 0

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for sc.Scan() {
		tokens = append(tokens, sc.Text())
	}
	solve()
}

// Move max function before solve to avoid forward reference
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve() {
	a := ni()
	b := ni()
	fmt.Println(max(0, a-2*b))
}

// ... (rest of the functions remain the same as before, with max function now placed before solve)

// End of Code
