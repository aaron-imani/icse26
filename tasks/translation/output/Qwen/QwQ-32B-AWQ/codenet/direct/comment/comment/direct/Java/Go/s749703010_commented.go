package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

var a [][2]int
var memo [][[][]int]

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanLines)

	sc.Scan() // Read n
	n, _ := strconv.Atoi(sc.Text())

	a = make([][2]int, n)

	sc.Scan() // Read first array line
	firstLine := sc.Text()
	fields := strings.Fields(firstLine)
	for i := 0; i < n; i++ {
		a[i][0], _ = strconv.Atoi(fields[i])
	}

	sc.Scan() // Read second array line
	secondLine := sc.Text()
	fields = strings.Fields(secondLine)
	for i := 0; i < n; i++ {
		a[i][1], _ = strconv.Atoi(fields[i])
	}

	// Initialize memo
	memo = make([][][]int, 2)
	for f := 0; f < 2; f++ {
		memo[f] = make([][]int, n+1)
		for i := 0; i <= n; i++ {
			memo[f][i] = make([]int, 1<<n)
			for m := range memo[f][i] {
				memo[f][i][m] = -1
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

func dp(flip, idx, msk int) int {
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
			if idx == n || a[idx][flip] <= a[i][(nf+(ff%2))%2] {
				newFlip := (nf + (ff % 2)) % 2
				res := ff + dp(newFlip, i, msk|(1<<i))
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

// End of Code
