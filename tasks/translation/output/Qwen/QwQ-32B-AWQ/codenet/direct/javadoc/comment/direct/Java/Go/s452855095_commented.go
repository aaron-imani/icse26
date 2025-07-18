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
	n, _ := strconv.Atoi(scanner.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		arr[i] = num
	}
	cnt := 0
	flag := true
	for {
		for i := 0; i < n; i++ {
			if arr[i]%2 != 0 {
				flag = false
				break
			}
			arr[i] /= 2
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
