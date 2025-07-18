// Correct Go translation of the Java code
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	solve()
}

func solve() {
	sc := bufio.NewScanner(os.Stdin)
	var H, W int
	if sc.Scan() {
		parts := strings.Fields(sc.Text())
		H, _ = strconv.Atoi(parts[0])
		W, _ = strconv.Atoi(parts[1])
	}

	c := make([][]int, 10)
	for i := range c {
		c[i] = make([]int, 10)
	}
	for i := 0; i < 10; i++ {
		sc.Scan()
		parts := strings.Fields(sc.Text())
		for j := 蹈 0; j < 10; j++ {
			c[i][j], _ = strconv.Atoi(parts[j])
		}
	}

	min := make([]int, 10)
	for i := 0; i < 10; i++ {
		min[i] = c[i][1]
	}

	for tc := 0; tc < 10; tc++ {
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				temp := c[i][j] + min[j]
				if temp < min[i] {
					min[i] = temp
				}
			}
		}
	}

	ans := 0
	for h := 0; h < H; h++ {
		sc.Scan()
		parts := strings.Fields(sc.Text())
		for _, part := range parts {
			A, _ := strconv.Atoi(part)
			if A >= 0 {
				ans += min[A]
			}
		}
	}
	fmt.Println(ans)
}
// End of Code
