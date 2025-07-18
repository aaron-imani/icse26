package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(sc *bufio.Reader, pr *bufio.Writer) {
	var n, k int
	fmt.Fscan(sc, &n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(sc, &a[i])
	}

	cumsum := make([]int, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + a[i]
	}

	b := []int{}
	max := 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			diff := cumsum[j+1] - cumsum[i]
			b = append(b, diff)
			if diff > max {
				max = diff
			}
		}
	}

	mask := 1 << uint(bitCount(max))
	for mask > 0 {
		tmp := []int{}
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
		ans := -1
		for _, e := range b {
			ans &= e
		}

		fmt.Fprintln(pr, ans)
	}
}

func bitCount(n int) int {
	count := 0
	for n > 0 {
		count++
		n &= n - 1
	}
	return count
}

func main() {
	sc := bufio.NewReader(os.Stdin)
	pr := bufio.NewWriter(os.Stdout)
	defer pr.Flush()

	solve(sc, pr)
}

// End of Code
