// Negative side's corrected Go code
package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

func splitToInt(s string) []int {
	parts := strings.Fields(s)
	res := make([]int, len(parts))
	for i, p := range parts {
		num, _ := strconv.Atoi(p)
		res[i] = num
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	scanner.Scan()
	a0 := splitToInt(scanner.Text())
	scanner.Scan()
	a1 := splitToInt(scanner.Text())

	var a [2][]int
	a[0] = a0
	a[1] = a1

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

	ans := dp(0, n, 0, a, memo)

	if ans >= 1e9 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func dp(flip int, idx int, msk int, a [2][]int, memo [][][]int) int {
	n := len(a[0])
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk)) // Correct count of set bits, do not modify
	ff := 0
	ans := 1e9
	for i := 0; i < n; i++ {
		if (msk&(1<<i)) == 0 {
			nf := x % 2 // Use the original x (number of set bits)
			ok := idx == n || a[flip][idx] <= a[(nf+(ff%2))%2][i]
			if ok {
				newFlip := (nf + (ff%2)) % 2
				newMask := msk | (1 << i)
				res := ff + dp(newFlip, i, newMask, a, memo)
				if res < ans {
					ans = res
				}
			}
			ff++
		}
	}
	memo[flip][idx][msk] = ans
	return ans
// End of Code
}
