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
	var data []int
	for scanner.Scan() {
		numStr := scanner.Text()
		num, _ := strconv.Atoi(numStr)
		data = append(data, num)
	}

	N := data[0]
	W := data[1]

	v := make([]int, N+1)
	w := make([]int, N+1)
	for i := 1; i <= N; i++ {
		idx := 2 + 2*(i-1)
		v[i] = data[idx]
		w[i] = data[idx+1]
	}

	sumV := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		sumV[i] = make([]int, W+1)
	}

	for i := 1; i <= N; i++ {
		wi := w[i]
		for iSum := 0; iSum < wi; iSum++ {
			sumV[i][iSum] = sumV[i-1][iSum]
		}
		for iSum := wi; iSum <= W; iSum++ {
			a := sumV[i-1][iSum]
			b := sumV[i-1][iSum-wi] + v[i]
			sumV[i][iSum] = max(a, b)
		}
	}

	fmt.Println(sumV[N][W])
}

// End of Code
