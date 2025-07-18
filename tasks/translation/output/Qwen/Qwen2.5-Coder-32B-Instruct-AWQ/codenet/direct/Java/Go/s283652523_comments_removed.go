package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N int
	fmt.Fscan(in, &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(in, &A[i])
	}

	ans := 0
	sum := A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans = (ans + (sum*A[i])%MOD) % MOD
		sum = (sum + A[i]) % MOD
	}
	fmt.Fprintln(out, ans)
}

func readInts(r *bufio.Reader, n int) []int {
	line, _ := r.ReadString('\n')
	strs := strings.Fields(line)
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.Atoi(strs[i])
	}
	return ints
}

// End of Code
