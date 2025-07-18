package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	if scanner.Scan() {
		n, _ = fmt.Sscanf(scanner.Text(), "%d")
	}
	a := make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			a[0][i], _ = fmt.Sscanf(scanner.Text(), "%d")
		}
	}
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			a[1][i], _ = fmt.Sscanf(scanner.Text(), "%d")
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
	var computeDP func(int, int, int) int
	computeDP = func(fliped int, idx int, msk int) int {
		if msk == (1<<n)-1 {
			return 0
		}
		if memo[fliped][idx][msk] != -1 {
			return memo[fliped][idx][msk]
		}
		x := bits.OnesCount(uint(msk))
		ans := 1 << 30
		ff := 0
		for i := 0; i < n; i++ {
			if (msk&(1<<i)) == 0 {
				nf := x % 2
				newFliped := (nf + (ff%2)) % 2
				if idx == n || a[fliped][idx] <= a[newFliped][i] {
					temp := ff + computeDP(newFliped, i, msk|(1<<i))
					if temp < ans {
						ans = temp
					}
				}
				ff++
			} else {
				x--
			}
		}
		memo[fliped][idx][msk] = ans
		return ans
	}
	ans := computeDP(0, n, 0)
	if ans >= 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}
// End of Code
