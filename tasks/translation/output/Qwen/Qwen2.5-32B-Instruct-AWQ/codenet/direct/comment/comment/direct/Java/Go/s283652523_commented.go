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

	ans := 0
	sum := A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans += (sum * A[i]) % MOD
		ans %= MOD
		sum += A[i]
		sum %= MOD
	}
	fmt.Fprintln(writer, ans)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}

// End of Code
