package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
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

		ans = int64(math.Min(float64(AAA), float64(BBB))) // 片方が端っこに来るまで。

		// 差を1減らす⇒差が偶数になる
		sa -= 1
		ans += 1

		// 差は偶数
		ans += sa / 2
	}

	fmt.Println(ans)
}

func next() string {
	var s string
	fmt.Scan(&s)
	return s
}

func nextInt() int {
	var i int
	fmt.Scan(&i)
	return i
}

func nextLong() int64 {
	var l int64
	fmt.Scan(&l)
	return l
}

func nextDouble() float64 {
	var d float64
	fmt.Scan(&d)
	return d
}

func splitString(s string) []string {
	return strings.Split(s, "")
}

func splitChar(s string) []rune {
	return []rune(s)
}

func charToInt(aaa rune) int {
	return int(aaa - '0')
}

func maxInt(a []int, lng int) int {
	max := a[0]
	for i := 1; i < lng; i++ {
		max = int(math.Max(float64(max), float64(a[i])))
	}
	return max
}

func minInt(a []int, lng int) int {
	min := a[0]
	for i := 1; i < lng; i++ {
		min = int(math.Min(float64(min), float64(a[i])))
	}
	return min
}

func maxLong(a []int64, lng int) int64 {
	max := a[0]
	for i := 1; i < lng; i++ {
		max = int64(math.Max(float64(max), float64(a[i])))
	}
	return max
}

func minLong(a []int64, lng int) int64 {
	min := a[0]
	for i := 1; i < lng; i++ {
		min = int64(math.Min(float64(min), float64(a[i])))
	}
	return min
}

// End of Code
