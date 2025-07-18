package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

var memo [][][]int
var a [2][]int
var n int

func dp(flip int, idx int, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ff := 0
	ans := 1000000000
	for i := 0; i < n; i++ {
		if (msk&(1<<i)) == 0 {
			nf := x % 2
			if idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i] {
				nextFlip := (nf + (ff%2)) % 2
				temp := ff + dp(nextFlip, i, msk|(1<<i))
				if temp < ans {
					ans = temp
				}
			}
			ff++
		}
	}
	memo[flip][idx][msk] = ans
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a[0] = make([]int, n)
	a[1] = make([]int, n)
	scanner.Scan()
	fields := strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		a[0][i], _ = strconv.Atoi(fields[i])
	}
	scanner.Scan()
	fields = strings.Fields(scanner.Text())
	for i := 0; i < n; i++ {
		a[1][i], _ = strconv.Atoi(fields[i])
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
	if ans >= 1000000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// End of Code
