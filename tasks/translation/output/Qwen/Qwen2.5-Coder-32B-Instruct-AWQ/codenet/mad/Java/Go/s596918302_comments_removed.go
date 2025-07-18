package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
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
	return int(math.Min(float64(op1), float64(op2)))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func dpc(arr [][]int, i int, n int, row int) int {
	if row == n {
		return 0
	}
	var j, k int
	if i == 1 {
		j = 0
		k = 2
	} else if i == 0 {
		j = 1
		k = 2
	} else {
		j = 0
		k = 1
	}

	return arr[row][i] + int(math.Max(float64(dpc(arr, j, n, row+1)), float64(dpc(arr, k, n, row+1))))
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
			dp[i][in] = int(math.Max(float64(dp[i-1][k]), float64(dp[i-1][j]))) + arr[i][in]
		}
	}

	return int(math.Max(float64(dp[n-1][0]), math.Max(float64(dp[n-1][1]), float64(dp[n-1][2]))))
}

// End of Code
