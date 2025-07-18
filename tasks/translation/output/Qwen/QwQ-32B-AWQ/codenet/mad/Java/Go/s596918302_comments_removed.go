// Negative's code with clarified function names and cleaner syntax
package main

import (
	"fmt"
	"math"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minAbs(arr []int, n int) int {
	if n == 1 {
		return 0
	}
	if n == 2 {
		return int(math.Abs(float64(arr[n-1] - arr[n-2])))
	}
	op1 := int(math.Abs(float64(arr[n-1]-arr[n-2]))) + minAbs(arr, n-1)
	op2 := int(math.Abs(float64(arr[n-1]-arr[n-3]))) + minAbs(arr, n-2)
	return min(op1, op2)
}

func dpc(arr [][]int, i, n, row int) int {
	if row == n {
		return 0
	}
	var j, k int
	switch i {
	case 1:
		j, k = 0, 2
	case 0:
		j, k = 1, 2
	default:
		j, k = 0, 1
	}
	return arr[row][i] + max(dpc(arr, j, n, row+1), dpc(arr, k, n, row+1))
}

func dpx(arr [][]int, n int) int {
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 3)
	}
	dp[0][0], dp[0][1], dp[0][2] = arr[0][0], arr[0][1], arr[0][2]
	for i := 1; i < n; i++ {
		for in := 0; in < 3; in++ {
			var j, k int
			switch in {
			case 1:
				j, k = 0, 2
			case 0:
				j, k = 1, 2
			default:
				j, k = 0, 1
			}
			prevMax := max(dp[i-1][j], dp[i-1][k])
			dp[i][in] = prevMax + arr[i][in]
		}
	}
	return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2])
}

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
// End of Code
