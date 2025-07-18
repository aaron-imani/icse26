package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func main() {
	sc.Split(bufio.ScanWords)

	n := nextLong()
	a := nextLong()
	b := nextLong()

	sa := int64(math.Abs(float64(a - b)))

	ans := int64(0)

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := int64(math.Min(float64(n-a), float64(a-1)))
		BBB := int64(math.Min(float64(n-b), float64(b-1)))

		ans = int64(math.Min(float64(AAA), float64(BBB))) //片方が端っこに来るまで。

		//差を1減らす⇒差が偶数になる
		sa -= 1
		ans += 1

		//差は偶数
		ans += sa / 2
	}

	fmt.Println(ans)
}

func next() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func nextLong() int64 {
	sc.Scan()
	i, e := strconv.ParseInt(sc.Text(), 10, 64)
	if e != nil {
		panic(e)
	}
	return i
}

func nextFloat() float64 {
	sc.Scan()
	i, e := strconv.ParseFloat(sc.Text(), 64)
	if e != nil {
		panic(e)
	}
	return i
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func splitString(s string) []string {
	return strings.Split(s, "")
}

func splitChar(s string) []rune {
	return []rune(s)
}

func charToInt(c byte) int {
	return int(c - '0')
}

func maxInt(a []int, lng int) int {
	max := a[0]
	for i := 1; i < lng; i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func minInt(a []int, lng int) int {
	min := a[0]
	for i := 1; i < lng; i++ {
		if a[i] < min {
			min = a[i]
		}
	}
	return min
}

func maxLong(a []int64, lng int) int64 {
	max := a[0]
	for i := 1; i < lng; i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func minLong(a []int64, lng int) int64 {
	min := a[0]
	for i := 1; i < lng; i++ {
		if a[i] < min {
			min = a[i]
		}
	}
	return min
}

// End of Code
