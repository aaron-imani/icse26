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
	sc.Split(bufio.ScanWords)

	N := nextInt(sc)
	W := nextInt(sc)

	v := make([]int, N+1)
	w := make([]int, N+1)

	for i := 1; i <= N; i++ {
		v[i] = nextInt(sc)
		w[i] = nextInt(sc)
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
			if sumV[i-1][iSum-w[i]]+v[i] > sumV[i-1][iSum] {
				sumV[i][iSum] = sumV[i-1][iSum-w[i]] + v[i]
			} else {
				sumV[i][iSum] = sumV[i-1][iSum]
			}
		}
	}

	fmt.Println(sumV[N][W])
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// End of Code
