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
	var n, k int
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		k, _ = strconv.Atoi(scanner.Text())
	}

	a := make([]int, n)
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			num, _ := strconv.Atoi(scanner.Text())
			a[i] = num
		}
	}

	cumsum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + int64(a[i])
	}

	b := make([]int64, 0)
	max := int64(0)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := cumsum[j+1] - cumsum[i]
			b = append(b, sum)
			if sum > max {
				max = sum
			}
		}
	}

	mask := int64(1)
	for mask <= max {
		mask <<= 1
	}
	mask >>= 1

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
