package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[0][i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a[1][i])
	}
	memo := make([][][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([][]int, n+1)
		for j := 0; j < n+1; j++ {
			size := 1 << n
			memo[i][j] = make([]int, size)
			for k := 0; k < size; k++ {
				memo[i][j][k] = -1
			}
		}
	}
	var dp func(int, int, int) int
	dp = func(flip int, idx int, mask int) int {
		if mask == (1<<n)-1 {
			return 0
		}
		if memo[flip][idx][mask] != -1 {
			return memo[flip][idx][mask]
		}
		x := bits.OnesCount(uint(mask))
		ans := 1000000000
		ff := 0
		for i := 0; i < n; i++ {
			if (mask&(1<<i)) == 0 {
				nf := x % 2
				var cond bool
				if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
					cond = true
				}
				if cond {
					newFlip := (nf + (ff % 2)) % 2
					newMask := mask | (1 << i)
					res := dp(newFlip, i, newMask)
					if res+ff < ans {
						ans = res + ff
					}
				}
				ff++
			} else {
				x--
			}
		}
		memo[flip][idx][mask] = ans
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
