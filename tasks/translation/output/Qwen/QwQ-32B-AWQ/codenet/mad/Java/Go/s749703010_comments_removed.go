// Negative's corrected code
package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
)

var a [2][]int
var memo [][][]int
var n int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	a0 := make([]int, n)
	a1 := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		a0[i] = num // Fixed assignment
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		a1[i] = num
	}

	a = [2][]int{a0, a1}

	memo = make([][][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([][]int, n+1)
		for j := 0; j < n+1; j++ {
			memo[i][j] = make([]int, 1<<n)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}

	ans := dp(0, n, 0)
	if ans >= 1e9 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func dp(flip int, idx int, msk int) int {
	if msk == (1<<n)-1 {
		return 0
	}
	if memo[flip][idx][msk] != -1 {
		return memo[flip][idx][msk]
	}
	x := bits.OnesCount(uint(msk))
	ans := 1000000000
	ff := 0
	for i := 0; i < n; i++ {
		if (msk&(1<<i)) == 0 {
			nf := x % 2
			currA := a[flip][idx]
			nextA := a[(nf+(ff%2))%2][i]
			if idx == n || currA <= nextA {
				newFlip := (nf + (ff%2)) % 2
				tmp := ff + dp(newFlip, i, msk|(1<<i))
				if tmp < ans {
					ans = tmp
				}
			}
			ff++
		} else {
			x-- // Correctly tracks bit count
		}
	}
	memo[flip][idx][msk] = ans
	return ans
}
// End of Code
