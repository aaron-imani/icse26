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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Fields(input)
	n, _ := strconv.ParseInt(parts[0], 10, 64)
	a, _ := strconv.ParseInt(parts[1], 10, 64)
	b, _ := strconv.ParseInt(parts[2], 10, 64)

	sa := int64(math.Abs(float64(a - b)))

	var ans int64 = 0

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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// End of Code
