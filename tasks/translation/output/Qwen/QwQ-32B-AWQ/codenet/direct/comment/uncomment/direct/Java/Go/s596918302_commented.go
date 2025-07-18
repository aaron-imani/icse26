package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	if sc.Scan() {
		n, _ = strconv.Atoi(sc.Text())
	}
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			if sc.Scan() {
				num, _ := strconv.Atoi(sc.Text())
				arr[i][j] = num
			}
		}
	}
	ans := dpx(arr, n)
	fmt.Println(ans)
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
	opt1 := dpc(arr, j, n, row+1)
	opt2 := dpc(arr, k, n, row+1)
	if opt1 > opt2 {
		return arr[row][i] + opt1
	}
	return arr[row][i] + opt2
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
				j = 越0
				k = 2
			} else if in == 0 {
				j = 1
				k = 2
			} else {
				j = 0
				k = 1
			}
			maxVal := dp[i-1][k]
			if dp[i-1][j] > maxVal {
				maxVal = dp[i-1][j]
			}
			dp[i][in] = maxVal + arr[i][in]
		}
	}
	maxVal := dp[n-1][0]
	if dp[n-1][1] > maxVal {
		maxVal = dp[n-1][1]
	}
	if dp[n-1][2] > maxVal {
		maxVal = dp[n-1][2]
	}
	return maxVal
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
	if op1 < op2 {
		return op1
	}
	return op2
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// End of Code
