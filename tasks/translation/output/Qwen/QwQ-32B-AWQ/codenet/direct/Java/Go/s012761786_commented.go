package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, a, b int64
	fmt.Scan(&n, &a, &b)

	sa := int64(math.Abs(float64(a - b)))

	var ans int64
	if sa%2 == 0 {
		ans = sa / 2
	} else {
		aaa := min(n-a, a-1)
		bbb := min(n-b, b-1)
		ans = min(aaa, bbb)
		sa -= 1
		ans += 1
		ans += sa / 2
	}
	fmt.Println(ans)
}

// End of Code
