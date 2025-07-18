package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Pair struct {
	l, r int
}

func (p Pair) String() string {
	return fmt.Sprintf("%d %d", p.l, p.r)
}

var memo [][][]int
var a [][]int
var n int

func dp(fliped, idx, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[fliped][idx][msk] != -1 {
		return memo[fliped][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ff := 0
	ans := 1e9
	for i := 0; i < n; i++ {
		if msk&(1<<i) == 0 {
			nf := x % 2
			if idx == n || a[fliped][idx] <= a[(nf+(ff%2))%2][i] {
				ans = min(ans, ff+dp((nf+(ff%2))%2, i, msk|1<<i))
			}
			ff++
		} else {
			x--
		}
	}
	memo[fliped][idx][msk] = ans
	return ans
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n = nextInt(sc)
	a = make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	for i := 0; i < n; i++ {
		a[0][i] = nextInt(sc)
	}
	for i := 0; i < n; i++ {
		a[1][i] = nextInt(sc)
	}
	memo = make([][][]int, 2)
	for i := range memo {
		memo[i] = make([][]int, n+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}
	ans := dp(0, n, 0)
	if ans >= 1e8 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of Code
