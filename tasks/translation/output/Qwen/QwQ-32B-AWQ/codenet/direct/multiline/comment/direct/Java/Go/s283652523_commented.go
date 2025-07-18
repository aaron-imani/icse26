package main

import (
	"fmt"
)

const MOD int64 = 1000000007

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	if n == 0 {
		fmt.Println(0)
		return
	}
	sum := int64(a[n-1])
	ans := int64(0)
	for i := n - 2; i >= 0; i-- {
		a_i := int64(a[i])
		productTerm := (sum * a_i) % MOD
		ans += productTerm
		ans %= MOD
		sum += a_i
		sum %= MOD
	}
	fmt.Println(ans % MOD)
}

// End of Code
