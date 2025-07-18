package main

import (
	"fmt"
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

	sa := a - b
	if sa < 0 {
		sa = -sa
	}

	var ans int64

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)
		ans = min(AAA, BBB)

		sa -= 
		ans += 1
		ans += sa / 2
	}

	fmt.Println(ans)
}

// End of Code
