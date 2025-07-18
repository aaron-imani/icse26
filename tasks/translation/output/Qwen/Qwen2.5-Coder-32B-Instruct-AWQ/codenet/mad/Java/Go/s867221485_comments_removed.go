package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	s := scanner.Text()

	ans := 0
	sha := 0
	dot := 0

	for i := 0; i < N; i++ {
		if s[i] == '#' {
			if sha <= dot {
				ans += sha
				sha = 0
				dot = 0
			}
			sha++
		} else {
			dot++
		}
	}

	if sha > dot {
		ans += sha
	}

	fmt.Println(ans)
}

// End of Code
