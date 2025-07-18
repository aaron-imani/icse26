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
		fmt.Println("Error reading input:", err)
		return
	}
	scanner.Scan()
	input := strings.Fields(scanner.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		var err error
		arr[i], err = strconv.Atoi(input[i])
		if err != nil {
			fmt.Println("Error reading input:", err)
			return
		}
	}
	cnt := 0
	flag := true
	for {
		flag = true
		for i := 0; i < n; i++ {
			if arr[i]%2 != 0 {
				flag = false
				break
			} else {
				arr[i] /= 2
			}
		}
		if flag {
			cnt++
		} else {
			break
		}
	}
	fmt.Println(cnt)
}
// End of Code
