package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	input := strings.Fields(sc.Text())
	n, _ := strconv.Atoi(input[0])
	k, _ := strconv.Atoi(input[1])

	a := make([]int, n)
	sc.Scan()
	input = strings.Fields(sc.Text())
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(input[i])
	}

	cumsum := make([]int, n+1)
	for i := 0; i < n; i++ {
		cumsum[i+1] = cumsum[i] + a[i]
	}

	b := make([]int, 0, n*(n+1)/2)
	max := 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			diff := cumsum[j+1] - cumsum[i]
			b = append(b, diff)
			if diff > max {
				max = diff
			}
		}
	}

	mask := 1 << (int(math.Log2(float64(max))) + 1)
	for mask > 0 {
		tmp := make([]int, 0)
		for _, e := range b {
			if e&mask != 0 {
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
		ans := -1
		for _, e := range b {
			ans &= e
		}
		fmt.Println(ans)
	}
}

func main() {
	solve()
}
// End of Code
