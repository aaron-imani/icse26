package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	pr := bufio.NewWriter(os.Stdout)
	defer pr.Flush()

	n := nextInt(sc)
	k := nextInt(sc)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	b := make([]int64, 0, n*(n+1)/2)
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

	mask := int64(1)
	for mask <= max {
		mask <<= 1
	}
	mask >>= 1

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
		fmt.Fprintln(pr, 0)
	} else {
		ans := int64(^uint64(0) >> 1)
		for _, e := range b {
			ans &= e
		}
		fmt.Fprintln(pr, ans)
	}
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
