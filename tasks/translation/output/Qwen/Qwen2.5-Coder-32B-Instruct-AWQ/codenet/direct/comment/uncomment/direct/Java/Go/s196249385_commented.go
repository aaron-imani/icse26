package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	pr := bufio.NewWriter(os.Stdout)
	defer pr.Flush()

	n := nextInt(sc)
	k := nextInt(sc)

	a := make([]int, n)
	for i := range a {
		a[i] = nextInt(sc)
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	var b []int64
	max := int64(0)
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
		var tmp []int64
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
		fmt.Fprintln(pr, 0)
	} else {
		ans := int64(-1)
		for _, e := range b {
			ans &= e
		}
		fmt.Fprintln(pr, ans)
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := fmt.Sscanf(sc.Text(), "%d")
	return i
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

// End of Code
