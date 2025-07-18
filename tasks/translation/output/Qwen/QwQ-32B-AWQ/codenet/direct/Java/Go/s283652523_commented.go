package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1e9 + 7

func solve(n int, a []int) int64 {
	ans := int64(0)
	sum := int64(a[n-1])
	for i := n - 2; i >= 0; i-- {
		term := sum * int64(a[i])
		ans = (ans + term%MOD) % MOD
		sum = (sum + int64(a[i])) % MOD
	}
	return ans % MOD
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		fmt.Sscanf(sc.Text(), "%d", &a[i])
	}
	ans := solve(n, a)
	fmt.Println(ans)
}

// End of Code
