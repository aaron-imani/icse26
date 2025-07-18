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

	n, _ := strconv.ParseInt(next(sc), 10, 64)
	a, _ := strconv.ParseInt(next(sc), 10, 64)
	b, _ := strconv.ParseInt(next(sc), 10, 64)

	sa := int64(math.Abs(float64(a - b)))

	ans := int64(0)

	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)

		ans = min(AAA, BBB)

		sa -= 1
		ans += 1

		ans += sa / 2
	}

	fmt.Println(ans)
}

func next(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
