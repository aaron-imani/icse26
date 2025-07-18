package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func nextLine() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	l := nextLine()
	i, e := strconv.Atoi(l)
	if e != nil {
		panic(e)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)

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
		for iSum := 0; iSum < w[i]; iSum++ {
			sumV[i][iSum] = sumV[i-1][iSum]
		}

		for iSum := w[i]; iSum <= W; iSum++ {
			sumV[i][iSum] = max(sumV[i-1][iSum], sumV[i-1][iSum-w[i]]+v[i])
		}
	}

	fmt.Println(sumV[N][W])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
