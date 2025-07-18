import (
	"fmt"
	"os"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minTwo(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
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
	return minTwo(op1, op2)
}

func dpc(arr [][]int, i, n, row int) int {
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
	return arr[row][i] + max(opt1, opt2)
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
			maxVal := max(dp[i-1][j], dp[i-1][k])
			dp[i][in] = maxVal + arr[i][in]
		}
	}
	return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))
}

func main() {
	var n int
	fmt.Fscanf(os.Stdin, "%d", &n)
	arr := make([][]int, n)
	for i := range arr {
		arr[i] = make([]int, 3)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < 3; j++ {
			var val int
			fmt.Fscanf(os.Stdin, "%d", &val)
			arr[i][j] = val
		}
	}
	ans := dpx(arr, n)
	fmt.Println(ans)
}

// End of Code
