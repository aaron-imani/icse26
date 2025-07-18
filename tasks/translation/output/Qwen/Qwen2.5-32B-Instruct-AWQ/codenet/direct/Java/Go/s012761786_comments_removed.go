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

		ans = int64(math.Min(float64(AAA), float64(BBB)))

		sa -= 1
		ans += 1

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

func maxInt(a []int) int {
	max := a[0]
	for _, v := range a[1:] {
		if v > max {
			max = v
		}
	}
	return max
}

func minInt(a []int) int {
	min := a[0]
	for _, v := range a[1:] {
		if v < min {
			min = v
		}
	}
	return min
}

func maxLong(a []int64) int64 {
	max := a[0]
	for _, v := range a[1:] {
		if v > max {
			max = v
		}
	}
	return max
}

func minLong(a []int64) int64 {
	min := a[0]
	for _, v := range a[1:] {
		if v < min {
			min = v
		}
	}
	return min
}

// End of Code
