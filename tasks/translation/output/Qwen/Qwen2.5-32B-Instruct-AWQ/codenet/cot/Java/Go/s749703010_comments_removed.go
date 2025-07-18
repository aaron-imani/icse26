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

func (p Pair) String() string {
	return fmt.Sprintf("%d %d", p.l, p.r)
}

var memo [2][101][1024]int
var a [2][101]int
var n int

func dp(flip int, idx int, msk int) int {
	if msk == (1 << n) - 1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ff := 0
	ans := 1000000000
	for i := 0; i < n; i++ {
		if (msk & (1 << i)) == 0 {
			nf := x % 2
			if idx == n || a[flip][idx] <= a[(nf + (ff % 2)) % 2][i] {
				ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)))
			}
			ff++
		} else {
			x--
		}
	}
	memo[flip][idx][msk] = ans
	return ans
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(sc.Text())
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		a[0][i], _ = strconv.Atoi(sc.Text())
	}
	for i := 0; i < n; i++ {
		a[1][i], _ = strconv.Atoi(sc.Text())
	}
	for i := 0; i < 2; i++ {
		for j := 0; j < n + 1; j++ {
			for k := 0; k < (1 << n); k++ {
				memo[i][j][k] = -1
			}
		}
	}
	ans := dp(0, n, 0)
	if ans >= 100000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
// End of Code
