package main

import (
	"bufio"
	"os"
	"strconv"
)

var idx int = 0
var tokens []string

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		tokens = append(tokens, scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic(err)
	}

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
		wi := w[i]
		upper := wi
		if upper > W {
			upper = W + 1
		}
		for j := 0; j < upper; j++ {
			sumV[i][j] = sumV[i-1][j]
		}
		start := wi
		if start > W {
			start = W + 1
		}
		for j := start; j <= W; j++ {
			option1 := sumV[i-1][j]
			option2 := sumV[i-1][j-wi] + v[i]
			sumV[i][j] = max(option1, option2)
		}
	}

	fmt.Println(sumV[N][W])
}

func nextInt() int {
	num, _ := strconv.Atoi(tokens[idx])
	idx++
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of Code
