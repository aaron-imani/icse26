package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	k := nextInt(sc)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
	}

	var cumsum []int64 = make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	var b []int64 = make([]int64, 0, n*(n+1)/2)
	var max int64 = 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := cumsum[j+1] - cumsum[i]
			b = append(b, sum)
			if sum > max {
				max = sum
			}
		}
	}

	var mask int64
	if max == 0 {
		mask = 0
	} else {
		mask = 1 << (63 - bits.LeadingZeros64(max))
	}

	for mask > 0 {
		var tmp []int64
		for _, e := range b {
			if (e & mask) != 0 {
				tmp = append(tmp, e)
			}
		}
		if len(tmp) >= k {
			b = tmp
		}
		mask >>= 1
	}

	if len(b) < k {
		fmt.Println(0)
	} else {
		ans := int64(-1)
		for _, e := range b {
			ans &= e
		}
		fmt.Println(ans)
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

// End of Code
