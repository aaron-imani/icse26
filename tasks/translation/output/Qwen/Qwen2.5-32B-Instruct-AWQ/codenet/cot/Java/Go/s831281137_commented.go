package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var so = bufio.NewWriter(os.Stdout)

func main() {
	N := nint()
	W := nint()

	v := make([]int, N+1)
	w := make([]int, N+1)

	for i := 1; i <= N; i++ {
		v[i] = nint()
		w[i] = nint()
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

	fmt.Fprintln(so, sumV[N][W])
	so.Flush()
}

func nint() int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nlong() int64 {
	sc.Scan()
	n, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return n
}

func nstr() string {
	sc.Scan()
	return sc.Text()
}

func nsToChars() []byte {
	sc.Scan()
	return []byte(sc.Text())
}

func nlongs(n int) []int64 {
	return nlongs(n, 0, 0)
}

func nints(n int) []int {
	return nints(n, 0, 0)
}

func nints(n, padL, padR int) []int {
	a := make([]int, padL+n+padR)
	for i := 0; i < n; i++ {
		a[padL+i] = nint()
	}
	return a
}

func nlongs(n, padL, padR int) []int64 {
	a := make([]int64, padL+n+padR)
	for i := 0; i < n; i++ {
		a[padL+i] = nlong()
	}
	return a
}

func nstrs(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = nstr()
	}
	return a
}

func nsToChars2D(h, w int) [][]byte {
	return nsToChars2D(h, w, 0)
}

func nsToChars2D(h, w, pad int) [][]byte {
	a2 := make([][]byte, h+pad*2)
	for i := range a2 {
		a2[i] = make([]byte, w+pad*2)
	}
	for i := 0; i < h; i++ {
		copy(a2[pad+i][pad:], nsToChars())
	}
	return a2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// End of Code
