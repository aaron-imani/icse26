package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	N   int
	ans int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	s := scanner.Text()

	flag := false
	hen := 0
	sha := 0
	dot := 0
	temp := 0
	first := true
	for i := 0; i < N; i++ {
		if s[i] == '#' {
			first = false
			if sha <= dot {
				ans += sha
				sha = 0
				dot = 0
				first = true
			}
			sha++
		} else {
			dot++
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	}

	fmt.Println(ans + dot)
}

// End of Code
