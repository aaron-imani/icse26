package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func init() {
	sc.Split(bufio.ScanWords)
}

func nint() int {
	sc.Scan()
	v, _ := strconv.Atoi(sc.Text())
	return v
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	N := nint()
	W := nint()

	v := make([]int, N+1)
	w := make([]int, N+1)
	for i := 1; i <= N; i++ {
		v[i] = nint()
		w[i] = nint()
	}

	sumV := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		sumV[i] = make([]int, W+1)
	}

	for i := 1; i <= N; i++ {
		for i_sum := 0; i_sum < w[i]; i_sum++ {
			sumV[i][i_sum] = sumV[i-1][i_sum]
		}
		for i_sum := w[i]; i_sum <= W; i_sum++ {
			a := sumV[i-1][i_sum]
			b := sumV[i-1][i_sum-w[i]] + v[i]
			sumV[i][i_sum] = max(a, b)
		}
	}

	fmt.Println(sumV[N][W])
}

// End of Code
