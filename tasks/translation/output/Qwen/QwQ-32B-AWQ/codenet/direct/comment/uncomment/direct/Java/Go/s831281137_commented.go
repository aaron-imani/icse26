package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N, W int
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		W, _ = strconv.Atoi(scanner.Text())
	}

	v := make([]int, N+1)
	w := make([]int, N+1)

	for i := 1; i <= N; i++ {
		if scanner.Scan() {
			v[i], _ = strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			w[i], _ = strconv.Atoi(scanner.Text())
		}
	}

	sumV := make([][]int, N+1)
	for i := range sumV {
		sumV[i] = make([]int, W+1)
	}

	for i := 1; i <= N; i++ {
		wi := w[i]
		for i_sum := 0; i_sum < wi; i_sum++ {
			sumV[i][i_sum] = sumV[i-1][i_sum]
		}
		for i_sum := wi; i_sum <= W; i_sum++ {
			sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum-wi]+v[i])
		}
	}

	fmt.Println(sumV[N][W])
}

// End of Code
