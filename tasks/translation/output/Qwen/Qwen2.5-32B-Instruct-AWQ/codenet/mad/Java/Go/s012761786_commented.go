package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextLong(sc)
	a := nextLong(sc)
	b := nextLong(sc)

	sa := int64(math.Abs(float64(a - b)))

	ans := int64(0)

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)

		ans = min(AAA, BBB) // 片方が端っこに来るまで。

		// 差を1減らす⇒差が偶数になる
		sa -= 1
		ans += 1

		// 差は偶数
		ans += sa / 2
	}

	fmt.Println(ans)
}

func nextLong(sc *bufio.Scanner) int64 {
	sc.Scan()
	num, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return num
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func nextDouble(sc *bufio.Scanner) float64 {
	sc.Scan()
	num, _ := strconv.ParseFloat(sc.Text(), 64)
	return num
}

func splitString(s string) []string {
	return strings.Split(s, "")
}

func splitChar(s string) []rune {
	return []rune(s)
}

func charToInt(c rune) int {
	return int(c - '0')
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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
