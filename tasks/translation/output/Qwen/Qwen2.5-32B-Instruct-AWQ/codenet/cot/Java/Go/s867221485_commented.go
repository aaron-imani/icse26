package main

import (
	"bufio"
	"fmt"
	"os"
)

var N int
var K int
var Q int64
var A int
var B int
var C int64
var min float64 = 9999999
var ans int64 = 0

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ = fmt.Sscan(scanner.Text(), N)

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
			dot++
		}
	}

	if sha <= dot {
		ans += sha
		dot = 0
	} else {
		temp += dot
	}

	fmt.Println(ans + dot) // End of Code
