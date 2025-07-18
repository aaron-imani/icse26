package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math/bits"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n, k int
	if sc.Scan() {
		n, _ = strconv.Atoi(sc.Text())
	} else {
		fmt.Fprintln(os.Stderr, "Error reading n")
		os.Exit(1)
	}
	if sc.Scan() {
		k, _ = strconv.Atoi(sc.Text())
	} else {
		fmt.Fprintln(os.Stderr, "Error reading k")
		os.Exit(1)
	}

	var a []int
	a = make([]int, n)
	for i := 0; i < n; i++ {
		if sc.Scan() {
			num, _ := strconv.Atoi(sc.Text())
			a[i] = num
		} else {
			fmt.Fprintln(os.Stderr, "Error reading array elements")
			os.Exit(1)
		}
	}

	var cumsum []int64
	cumsum = make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	var b []int64
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
		mask = 1 << (bits.Len64(max) - 1)
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

// End of Code
