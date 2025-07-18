package main

import (
	"fmt"
	"math"
)

func main() {
	var n, a, b int64
	fmt.Scan(&n, &a, &b)

	sa := int64(math.Abs(float64(a - b)))

	var ans int64

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := int64(math.Min(float64(n-a), float64(a-1)))
		BBB := int64(math.Min(float64(n-b), float64(b-1)))

		ans = int64(math.Min(float64(AAA), float64(BBB))) // one side reaches the edge.

		// reduce difference by 1 => difference becomes even
		sa -= 1
		ans += 1

		// difference is now even
		ans += sa / 2
	}

	fmt.Println(ans)
}

// End of Code
