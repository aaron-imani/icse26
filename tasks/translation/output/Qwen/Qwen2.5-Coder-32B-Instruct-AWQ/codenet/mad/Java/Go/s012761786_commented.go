package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func main() {
	sc.Split(bufio.ScanWords)

	n := nextLong()
	a := nextLong()
	b := nextLong()

	sa := abs(a - b)

	var ans int64

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)

		ans = min(AAA, BBB) //片方が端っこに来るまで。

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

func nextLong() int64 {
	l, _ := strconv.ParseInt(next(), 10, 64)
	return l
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// End of Code
