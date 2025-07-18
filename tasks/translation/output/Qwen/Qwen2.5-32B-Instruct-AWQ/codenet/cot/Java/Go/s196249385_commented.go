package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(sc *bufio.Scanner, pr *bufio.Writer) {
	n := nextInt(sc)
	k := nextInt(sc)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
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

	mask := 1 << (31 - int(math.Log2(float64(max))))
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
		pr.WriteString("0\n")
	} else {
		ans := -1
		for _, e := range b {
			ans &= e
		}

		pr.WriteString(fmt.Sprintf("%d\n", ans))
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	pr := bufio.NewWriter(os.Stdout)
	defer pr.Flush()

	solve(sc, pr)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

// End of Code
