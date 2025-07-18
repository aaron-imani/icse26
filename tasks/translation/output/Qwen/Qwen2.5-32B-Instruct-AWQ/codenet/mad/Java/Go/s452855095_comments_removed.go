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
	n, _ := strconv.Atoi(scanner.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}
	cnt := 0
	for {
		flag := true // Reset flag to true at the beginning of each iteration
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
