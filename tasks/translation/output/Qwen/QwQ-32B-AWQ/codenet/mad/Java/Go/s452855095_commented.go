package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := range arr {
		fmt.Scan(&arr[i])
	}
	cnt := 0
	for {
		flag := true
		for i := 0; i < n; i++ {
			if arr[i]%2 != 0 {
				flag = false
				break
			}
		}
		if !flag {
			break
		}
		for i := 0; i < n; i++ {
			arr[i] /= 2
		}
		cnt++
	}
	fmt.Println(cnt)
	// End of Code
}
