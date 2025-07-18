package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)
var so = os.Stdout

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
			if sumV[i-1][iSum-w[i]]+v[i] > sumV[i-1][iSum] {
				sumV[i][iSum] = sumV[i-1][iSum-w[i]] + v[i]
			} else {
				sumV[i][iSum] = sumV[i-1][iSum]
			}
		}
	}

	fmt.Fprintln(so, sumV[N][W])
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextStrings(n int) []string {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		strs[i] = nextString()
	}
	return strs
}

func nextInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = nextInt()
	}
	return ints
}

func nextFloat64() float64 {
	sc.Scan()
	f, e := strconv.ParseFloat(sc.Text(), 64)
	if e != nil {
		panic(e)
	}
	return f
}

func nextFloat64s(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i] = nextFloat64()
	}
	return floats
}

func nextLine() string {
	sc.Scan()
	return strings.TrimSpace(sc.Text())
}

// End of Code
