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
		var AAA, BBB int64
		AAA = n - a
		if (a-1) < AAA {
			AAA = a - 1
		}

		BBB = n - b
		if (b-1) < BBB {
			BBB = b - 1
		}

		if AAA < BBB {
			ans = AAA
		} else {
			ans = BBB
		}

		sa -= 1
		ans += 1
		ans += sa / 2
	}

	fmt.Println(ans)
}

// End of Code
