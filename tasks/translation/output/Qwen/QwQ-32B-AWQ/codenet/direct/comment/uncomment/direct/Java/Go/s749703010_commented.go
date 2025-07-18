package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	var n int
	if scanner.Scan() {
		n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
	}
	a := make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	if scanner.Scan() {
		parts := strings.Fields(scanner.Text())
		for i := 0; i < n; i++ {
			a[0][i], _ = strconv.Atoi(parts[i])
		}
	}
	if scanner.Scan() {
		parts := strings.Fields(scanner.Text())
		for i := 0; i < n; i++ {
			a[1][i], _ = strconv.Atoi(parts[i])
		}
	}
	memo := make([][][]int, 2)
	for i := range memo {
		memo[i] = make([][]int, n+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}
	var dp func(flip, idx, msk int) int
	dp = func(flip, idx, msk int) int {
		if msk == (1<<n)-1 {
			return 0
		}
		if memo[flip][idx][msk] != -1 {
			return memo[flip][idx][msk]
		}
		x := bits.OnesCount(uint(msk))
		ans := 1000000000
		ff := 0
		for i := 0; i < n; i++ {
			if (msk&(1<<i)) == 0 {
				nf := x % 2
				if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
					newFlip := (nf + (ff % 2)) % 2
					res := ff + dp(newFlip, i, msk|(1<<i))
					if res < ans {
						ans = res
					}
				}
				ff++
			} else {
				x--
			}
		}
		memo[flip][idx][msk] = ans
		return ans
	}
	ans := dp(0, n, 0)
	if ans >= 1000000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// End of Code
