package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([][]int, n)
	for i := range arr {
		arr[i] = make([]int, 3)
		for j := range arr[i] {
			fmt.Scan(&arr[i][j])
		}
	}

	ans := dpx(arr, n)
	fmt.Println(ans)
}

func min(arr []int, n int) int {
	if n == 1 {
		return 0
	}
	if n == 2 {
		return abs(arr[n-1] - arr[n-2])
	}
	op1 := abs(arr[n-1]-arr[n-2]) + min(arr, n-1)
	op2 := abs(arr[n-1]-arr[n-3]) + min(arr, n-2)
	res := minInt(op1, op2)
	return res
}

func dpc(arr [][]int, i int, n int, row int) int {
	if row == n {
		return 0
	}
	j, k := 0, 0
	if i == 1 {
		j, k = 0, 2
	} else if i == 0 {
		j, k = 1, 2
	} else {
		j, k = 0, 1
	}
	return arr[row][i] + max(dpc(arr, j, n, row+1), dpc(arr, k, n, row+1))
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
			j, k := 0, 0
			if in == 1 {
				j, k = 0, 2
			} else if in == 0 {
				j, k = 1, 2
			} else {
				j, k = 0, 1
			}
			dp[i][in] = max(dp[i-1][k], dp[i-1][j]) + arr[i][in]
		}
	}

	return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func minInt(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
// End of Code
