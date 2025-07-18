package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	s := scanner.Text()

	flag := false
	ans := 0
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
			} else {
				temp += dot
			}
			sha++
		} else {
			if !first {
				dot++
			}
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	} else {
		temp += dot
	}

	fmt.Println(ans + dot) // End of Code
