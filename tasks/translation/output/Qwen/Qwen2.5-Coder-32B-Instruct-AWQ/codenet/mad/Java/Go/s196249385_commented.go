package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc *bufio.Scanner
var wr *bufio.Writer

func nextInt() int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextLong() int64 {
	sc.Scan()
	i, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return i
}

func solve() {
	n := nextInt()
	k := nextInt()

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt()
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	b := make([]int64, 0, n*(n+1)/2)
	var max int64
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			diff := cumsum[j+1] - cumsum[i]
			b = append(b, diff)
			if diff > max {
				max = diff
			}
		}
	}

	mask := highestOneBit(max)
	for mask > 0 {
		tmp := make([]int64, 0)
		for _, e := range b {
			if e&mask != 0 {
				tmp = append(tmp, e)
			}
		}

		if len(tmp) >= k {
			b = tmp
		}

		mask >>= 1
	}

	if len(b) < k {
		fmt.Fprintln(wr, 0)
	} else {
		ans := int64(-1)
		for _, e := range b {
			ans &= e
		}

		fmt.Fprintln(wr, ans)
	}
}

func highestOneBit(x int64) int64 {
	if x == 0 {
		return 0
	}
	x |= x >> 1
	x |= x >> 2
	x |= x >> 4
	x |= x >> 8
	x |= x >> 16
	x |= x >> 32
	return x - (x >> 1)
}

func main() {
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	wr = bufio.NewWriter(os.Stdout)
	defer wr.Flush()

	solve()
}

// End of Code
