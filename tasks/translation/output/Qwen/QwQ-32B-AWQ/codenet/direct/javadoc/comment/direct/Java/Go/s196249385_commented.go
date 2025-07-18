package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, k int
	if !scanner.Scan() {
		panic("error reading n")
	}
	n, _ = strconv.Atoi(scanner.Text())
	if !scanner.Scan() {
		panic("error reading k")
	}
	k, _ = strconv.Atoi(scanner.Text())

	a := make([]int64, n)
	for i := range a {
		if !scanner.Scan() {
			panic("error reading a")
		}
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		a[i] = num
	}

	// Compute cumulative sums
	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + a[i]
	}

	// Build all possible subarray sums and track max
	var b []int64
	var max int64
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := cumsum[j+1] - cumsum[i]
			b = append(b, sum)
			if sum > max {
				max = sum
			}
		}
	}

	// Determine the initial mask
	var mask int64
	if max > 0 {
		mask = 1 << (bits.Len64(max) - 1)
	} else {
		mask = 0
	}

	// Iterate over each bit from highest to lowest
	for mask > 0 {
		tmp := make([]int64, 0, len(b))
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

// End of Code
