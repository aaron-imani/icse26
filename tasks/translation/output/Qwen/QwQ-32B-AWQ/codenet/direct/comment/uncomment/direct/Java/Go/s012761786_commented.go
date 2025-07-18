package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n := nextInt64(sc)
	a := nextInt64(sc)
	b := nextInt64(sc)

	sa := a - b
	if sa < 0 {
		sa = -sa
	}

	var ans int64 = 0

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)
		minAB := min(AAA, BBB)
		ans = minAB
		ans += 1
		sa -= 1
		ans += sa / 2
	}

	fmt.Println(ans)
}

func nextInt64(sc *bufio.Scanner) int64 {
	sc.Scan()
	numStr := sc.Text()
	num, _ := strconv.ParseInt(numStr, 10, 64)
	return num
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
