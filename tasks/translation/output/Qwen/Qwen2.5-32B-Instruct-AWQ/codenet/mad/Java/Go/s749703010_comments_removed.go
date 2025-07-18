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

var memo [2][100][1024]int
var a [2][100]int
var n int

func dp(flip, idx, msk int) int {
	if msk == (1 << n) - 1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bitCount(msk)
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

func bitCount(n int) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n = readInt(sc)
	a = [2][100]int{}
	for i := 0; i < n; i++ {
		a[0][i] = readInt(sc)
	}
	for i := 0; i < n; i++ {
		a[1][i] = readInt(sc)
	}
	for i := range memo {
		for j := range memo[i] {
			for k := range memo[i][j] {
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

func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}
// End of Code
