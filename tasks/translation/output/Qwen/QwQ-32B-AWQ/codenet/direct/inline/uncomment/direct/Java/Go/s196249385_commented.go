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
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ := strconv.Atoi(sc.Text())

	a := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		a[i] = num
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	var b []int64
	max := int64(0)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			val := cumsum[j+1] - cumsum[i]
			b = append(b, val)
			if val > max {
				max = val
			}
		}
	}

	mask := int64(0)
	if max > 0 {
		mask = 1 << (bits.Len64(max) - 1)
	}

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
