package main

import (
	"fmt"
)

func main() {
	var n, a, b int64
	fmt.Scan(&n)
	fmt.Scan(&a)
	fmt.Scan(&b)

	sa := a - b
	if sa < 0 {
		sa = -sa
	}

	var ans int64
	if sa%2 == 0 {
		ans = sa / 2
	} else {
		aaa := n - a
		if (a-1) < aaa {
			aaa = a - 1
		}
		bbb := n - b
		if (b-1) < bbb {
			bbb = b - 1
		}
		ans = aaa
		if bbb < ans {
			ans = bbb
		}
		sa -= 1
		ans += 1
		ans += sa / 2
	}
	fmt.Println(ans)
}

// End of Code
