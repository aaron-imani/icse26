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
			takeItem := sumV[i-1][i_sum-w[i]] + v[i]
			notTake := sumV[i-1][i_sum]
			if notTake > takeItem {
				sumV[i][i_sum] = notTake
			} else {
				sumV[i][i_sum] = takeItem
			}
		}
	}

	fmt.Println(sumV[N][W])
}

// End of Code
