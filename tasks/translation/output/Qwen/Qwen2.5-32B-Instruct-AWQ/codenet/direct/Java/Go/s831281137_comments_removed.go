package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	N := readInt(sc)
	W := readInt(sc)

	v := make([]int, N+1)
	w := make([]int, N+1)

	for i := 1; i <= N; i++ {
		v[i] = readInt(sc)
		w[i] = readInt(sc)
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
			sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum-w[i]]+v[i])
		}
	}

	fmt.Println(sumV[N][W])
}

func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
