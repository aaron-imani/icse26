package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	pr := bufio.NewWriter(os.Stdout)
	defer pr.Flush()

	solve(sc, pr)
}

func solve(sc *bufio.Scanner, pr *bufio.Writer) {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ := strconv.Atoi(sc.Text())

	a := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
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

	mask := int64(1)
	for mask <= max {
		mask <<= 1
	}
	mask >>= 1

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
		ans := int64(^uint64(0) >> 1)
		for _, e := range b {
			ans &= e
		}

		fmt.Fprintln(pr, ans)
	}
}
// End of Code
