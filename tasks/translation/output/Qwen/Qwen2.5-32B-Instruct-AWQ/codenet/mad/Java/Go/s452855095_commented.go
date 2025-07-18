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
	n, err := strconv.Atoi(scanner.Text())
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		os.Exit(1)
	}
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i], err = strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Fprintln(os.Stderr, "Error reading input:", err)
			os.Exit(1)
		}
	}
	cnt := 0
	for {
		flag := true
		for i := 0; i < n; i++ {
			if arr[i]%2 != 0 {
				flag = false
				break
			} else {
				arr[i] = arr[i] / 2
			}
		}
		if flag {
			cnt++
		} else {
			break
		}
	}
	fmt.Println(cnt) // End of Code
}
