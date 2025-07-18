package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	H, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	W, _ := strconv.Atoi(sc.Text())
	sc.Scan()

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			c[i][j], _ = strconv.Atoi(sc.Text())
			sc.Scan()
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				if c[i][j]+min[j] < min[i] {
					min[i] = c[i][j] + min[j]
				}
			}
		}
	}

	ans := 0
	for h := 1; h <= H; h++ {
		for w := 1; w <= W; w++ {
			A, _ := strconv.Atoi(sc.Text())
			sc.Scan()
			if A >= 0 {
				ans += min[A]
			}
		}
	}

	fmt.Println(ans)
}

// End of Code
