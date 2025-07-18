package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Pair struct {
	l int
	r int
}

func dp(flip int, idx int, msk int, a [][]int, memo [][][]int, n int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ff := 0
	ans := int(1e9)
	for i := 0; i < n; i++ {
		if (msk&(1<<i)) == 0 {
			nf := x % 2
			if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
				ans = min(ans, ff+dp((nf+(ff%2))%2, i, msk|1<<i, a, memo, n))
			}
			ff++
		} else {
			x--
		}
	}
	memo[flip][idx][msk] = ans
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(scanner.Text())
	a := make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[0][i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[1][i], _ = strconv.Atoi(scanner.Text())
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
	ans := dp(0, n, 0, a, memo, n)
	if ans >= int(1e8) {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// End of Code
