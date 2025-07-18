Here's the Go code translation of the provided Java code:


import (
	"fmt"
	"math/bits"
)

func main() {
	const inf = 1e9
	var n int
	fmt.Scan(&n)
	a0 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a0[i])
	}
	a1 := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a1[i])
	}
	a := [2][]int{a0, a1}
	memo := make([][][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([][]int, n+1)
		for j := 0; j < n+1; j++ {
			memo[i][j] = make([]int, 1<<n)
			for k := 0; k < 1<<n; k++ {
				memo[i][j][k] = -1
			}
		}
	}
	var dp func(flip int, idx int, msk int) int
	dp = func(flip int, idx int, msk int) int {
		if msk == (1<<n-1) {
			return 0
		}
		if memo[flip][idx][msk] != -1 {
			return memo[flip][idx][msk]
		}
		x := bits.OnesCount(uint(msk))
		ans := inf
		ff := 0
		for i := 0; i < n; i++ {
			if (msk&(1<<i)) == 0 {
				nf := x % 2
				if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
					newFlip := (nf + (ff%2)) % 2
					newMsk := msk | (1 << i)
					res := ff + dp(newFlip, i, newMsk)
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
	if ans >= inf {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}
// End of Code
