package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([][]int, 2)
	a[0] = make([]int, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		a[0][i] = x
	}
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		a[1][i] = x
	}
	memo := make([][][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([][]int, n+1)
		for j := 0; j < n+1; j++ {
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
		x := bits.OnesCount32(uint32(msk))
		ff := 0
		ans := 1000000000
		for i := 0; i < n; i++ {
			if (msk&(1<<i)) == 0 {
				nf := x % 2
				nextFlip := (nf + (ff%2)) % 2
				if idx == n || a[flip][idx] <= a[nextFlip][i] {
					newMsk := msk | (1 << i)
					res := ff + dp(nextFlip, i, newMsk)
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
