package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Split(bufio.ScanWords)
	a := nextInt(in)
	b := nextInt(in)
	q := nextInt(in)

	s := make([]int64, a+2)
	t := make([]int64, b+2)
	s[0], t[0] = -10000000000, -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = nextInt64(in)
	}
	for i := 0; i < b; i++ {
		t[i+1] = nextInt64(in)
	}
	s[a+1], t[b+1] = 20000000000, 20000000000

	for i := 0; i < q; i++ {
		x := nextInt64(in)
		sl := x - s[max(0, lowerBound(s, x+1)-1)]
		tl := x - t[max(0, lowerBound(t, x+1)-1)]
		sr := s[lowerBound(s, x)] - x
		tr := t[lowerBound(t, x)] - x
		ans := min(
			max(sl, tl),
			max(sr, tr),
			2*sl+tr,
			2*tl+sr,
			sl+2*tr,
			tl+2*sr,
		)
		fmt.Fprintln(out, ans)
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	i, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return i
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func maxInt64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func lowerBound(arr []int64, target int64) int {
	min, max := 0, len(arr)
	for min < max {
		mid := (min + max) / 2
		if target <= arr[mid] {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

// End of Code
