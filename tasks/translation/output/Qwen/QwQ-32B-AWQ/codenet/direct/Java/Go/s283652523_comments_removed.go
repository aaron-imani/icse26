package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		A[i] = num
	}
	MOD := int64(1e9 + 7)
	ans := int64(0)
	sum := A[N-1] % MOD
	for i := N - 2; i >= 0; i-- {
		temp := (sum * A[i]) % MOD
		ans = (ans + temp) % MOD
		sum = (sum + A[i]) % MOD
	}
	fmt.Println(ans % MOD)
}

// End of Code
