package main

import (
	"fmt"
)

func min64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, a, b int64
	fmt.Scan(&n, &a, &b)

	sa := a - b
	if sa < 0 {
		sa = -sa
	}

	var ans int64
	if sa%2 == _ {
		ans = sa / 2
	} else {
		aaa := min64(n-a, a-1)
		bbb := min64(n-b, b-1)
		minVal := min64(aaa, bbb)
		ans = minVal
		sa -= 1
		ans += 1
		ans += sa / 2
	}
	fmt.Println(ans)
}

// End of Code
