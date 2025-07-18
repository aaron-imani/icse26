package main

import (
	"fmt"
)

func main() {
	var N, W int
	fmt.Scan(&N, &W)

	v := make([]int, N+1)
	w := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&v[i], &w[i])
	}

	sumV := make([][]int, N+1)
	for i := range sumV {
		sumV[i] = make([]int, W+1)
	}

	for i := 1; i <= N; i++ {
		for i_sum := 0; i_sum < w[i]; i_sum++ {
			sumV[i][i_sum] = sumV[i-1][i_sum]
		}
		for i_sum := w[i]; i_sum <= W; i_sum++ {
			option1 := sumV[i-1][i_sum]
			option2 := sumV[i-1][i_sum-w[i]] + v[i]
			if option2 > option1 {
				sumV[i][i_sum] = option2
			} else {
				sumV[i][i_sum] = option1
			}
		}
	}

	fmt.Println(sumV[N][W])
}

// End of Code
