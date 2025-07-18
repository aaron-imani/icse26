package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
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
	fmt.Println(cnt)
	// End of Code
}
