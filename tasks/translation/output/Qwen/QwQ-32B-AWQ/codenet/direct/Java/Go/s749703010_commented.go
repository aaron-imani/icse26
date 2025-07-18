package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	a := make([][]int, 2)
	a[0] = make([]int, n)
	a[1] = make([]int, n)

	nums0, _ := readInts(reader)
	for i := 0; i < n; i++ {
		a[0][i] = nums0[i]
	}

	nums1, _ := readInts(reader)
	for i := 0; i < n; i++ {
		a[1][i] = nums1[i]
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

	var dp func(flip, idx, msk int) int
	dp = func(flip, idx, msk int) int {
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
				nextFlip := (nf + (ff%2)) % 2
				nextAVal := a[nextFlip][i]
				var conditionMet bool
				if idx == n {
					conditionMet = true
				} else {
					currentA := a[flip][idx]
					conditionMet = currentA <= nextAVal
				}
				if conditionMet {
					res := ff + dp(nextFlip, i, msk|(1<<i))
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
	if ans >= 1000000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func readLine(r *bufio.Reader) string {
	line, _, _ := r.ReadLine()
	return string(line)
}

func readInts(r *bufio.Reader) ([]int, error) {
	line, _, err := r.ReadLine()
	if err != nil {
		return nil, err
	}
	parts := strings.Fields(string(line))
	nums := make([]int, len(parts))
	for i, s := range parts {
		num, _ := strconv.Atoi(s)
		nums[i] = num
	}
	return nums, nil
}

// End of Code
