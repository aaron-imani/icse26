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
	sc.Scan()
	H, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	W, _ := strconv.Atoi(sc.Text())

	c := make([][]int, 10)
	for i := 0; i < 10; i++ {
		c[i] = make([]int, 10)
		for j := 0; j < 10; j++ {
			sc.Scan()
			c[i][j], _ = strconv.Atoi(sc.Text())
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				if min[i] > c[i][j]+min[j] {
					min[i] = c[i][j] + min[j]
				}
			}
		}
	}

	ans := 0
	for h := 0; h < H; h++ {
		for w := 0; w < W; w++ {
			sc.Scan()
			A, _ := strconv.Atoi(sc.Text())
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}

// End of Code
