package main

import (
	"fmt"
	"math"
)

func main() {
	var n, a, b int64
	fmt.Scanf("%d %d %d", &n, &a, &b)
	sa := int64(math.Abs(float64(a - b)))

	var ans int64 = 0

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := int64(math.Min(float64(n-a), float64(a-1)))
		BBB := int64(math.Min(float64(n-b), float64(b-1)))

		ans = int64(math.Min(float64(AAA), float64(BBB))) // 片方が端っこに来るまで。

		// 差を1減らす⇒差が偶数になる
		sa -= 1
		ans += 1

		// 差は偶数
		ans += sa / 2
	}

	fmt.Println(ans)
}

// End of Code
