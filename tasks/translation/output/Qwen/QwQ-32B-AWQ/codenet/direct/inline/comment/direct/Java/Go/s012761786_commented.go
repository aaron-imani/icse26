package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, a, b int64
	if scanner.Scan() {
		n, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	if scanner.Scan() {
		a, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}
	if scanner.Scan() {
		b, _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}

	sa := int64(0)
	if a > b {
		sa = a - b
	} else {
		sa = b - a
	}

	var ans int64
	if sa%2 == 0 {
		ans = sa / 2
	} else {
		AAA := min(n-a, a-1)
		BBB := min(n-b, b-1)
		minAB := min(AAA, BBB)
		ans = minAB
		sa -= 1
		ans += 1
		ans += sa / 2
	}
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
