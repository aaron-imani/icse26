package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	var n, a, b int64

	if sc.Scan() {
		n, _ = strconv.ParseInt(sc.Text(), 10, 64)
	} else {
		fmt.Println("Error reading input")
		return
	}

	if sc.Scan() {
		a, _ = strconv.ParseInt(sc.Text(), 10, 64)
	} else {
		fmt.Println("Error reading input")
		return
	}

	if sc.Scan() {
		b, _ = strconv.ParseInt(sc.Text(), 10, 64)
	} else {
		fmt.Println("Error reading input")
		return
	}

	sa := abs(a - b)

	var ans int64
	if sa%2 == 0 {
		ans = sa / 2
	} else {
		aaa := min(n-a, a-1)
		bbb := min(n-b, b-1)
		ans = min(aaa, bbb)
		sa -= 1
		ans += 1
		ans += sa / 2
	}

	fmt.Println(ans)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

// End of Code
