package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

func solve(reader *bufio.Reader, writer *bufio.Writer) {
	var N int
	fmt.Fscan(reader, &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	ans, sum := 0, A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans += (sum * A[i]) % MOD
		ans %= MOD
		sum += A[i]
		sum %= MOD
	}
	fmt.Fprintln(writer, ans)
	writer.Flush()
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	solve(reader, writer)
}

// End of Code
