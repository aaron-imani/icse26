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
	var flag bool = true

	for {
		for i := 0; i < len(arr); i++ {
			if arr[i]%2 != 0 {
				flag = false
				break
			}
			arr[i] /= 2
		}
		if !flag {
			break
		}
		cnt++
	}

	fmt.Println(cnt)
}

// End of Code
