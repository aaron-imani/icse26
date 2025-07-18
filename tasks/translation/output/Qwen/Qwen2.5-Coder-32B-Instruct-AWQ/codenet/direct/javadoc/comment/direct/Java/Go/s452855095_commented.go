package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	cnt := 0
	flag := true
	for {
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
		flag = true
	}
	fmt.Println(cnt)
}
// End of Code
