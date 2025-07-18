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
		allEven := true
		for i := range arr {
			if arr[i]%2 != 0 {
				allEven = false
				break
			}
			arr[i] /= 2
		}
		if allEven {
			cnt++
		} else {
			break
		}
	}
	fmt.Println(cnt)
}
// End of Code
