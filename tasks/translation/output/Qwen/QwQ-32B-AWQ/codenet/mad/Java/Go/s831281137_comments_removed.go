package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc *bufio.Scanner

func init() {
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
}

func nextInt() int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	N := nextInt()
	W := nextInt()

	v := make([]int, N+1)
	w := make([]int, N+1)

	for i := 1; i <= N; i++ {
		v[i] = nextInt()
		w[i] = nextInt()
	}

	sumV := make([][]int, N+1)
	for i := range sumV {
		sumV[i] = make([]int, W+1)
	}

	for i := 1; i <= N; i++ {
		maxFirst := w[i]
		if maxFirst > W {
			maxFirst = W
		}
		for i_sum := 0; i_sum < maxFirst; i_sum++ {
			sumV[i][i_sum] = sumV[i-1][i_sum]
		}
		for i_sum := w[i]; i_sum <= W; i_sum++ {
			sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum-w[i]]+v[i])
		}
	}

	fmt.Println(sumV[N][W])
}
// End of Code
