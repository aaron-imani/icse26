package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dpx(arr [][]int, n int) int {
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 3)
	}
	dp[0][0] = arr[0][0]
	dp[0][1] = arr[0][1]
	dp[0][2] = arr[0][2]

	for i := 1; i < n; i++ {
		for in := 0; in < 3; in++ {
			var j, k int
			if in == 1 {
				j = 0
				k = 2
			} else if in == 0 {
				j = 1
				k = 2
			} else {
				j = 0
				k = 1
			}
			dp[i][in] = max(dp[i-1][j], dp[i-1][k]) + arr[i][in]
		}
	}

	return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
	}
	ans := dpx(arr, n)
	fmt.Println(ans)
}
// End of Code
