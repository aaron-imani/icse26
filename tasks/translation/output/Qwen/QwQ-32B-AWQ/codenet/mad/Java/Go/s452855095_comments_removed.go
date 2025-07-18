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
	scanner.Scan()
	parts := strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(parts[i])
		arr[i] = num
	}
	cnt := 0
	for {
		flag := true // Reset flag at the start of each loop iteration
		for i := 0; i < len(arr); i++ {
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
	// End of Code
}
