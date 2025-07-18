package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		A[i] = num
	}
	const MOD = 1000000007 // Correct MOD declaration
	var ans int64
	var sum int64 = int64(A[N-1])
	for i := N - 2; i >= 0; i-- {
		prod := sum * int64(A[i])
		ans += prod % MOD
		ans %= MOD
		sum += int64(A[i])
		sum %= MOD
	}
	fmt.Println(ans % MOD)
}
// End of Code
