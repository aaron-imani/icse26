package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	N := readInt(in)
	A := make([]int, N)
	for i := range A {
		A[i] = readInt(in)
	}

	ans := 0
	sum := A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans = (ans + (sum*A[i])%MOD) % MOD
		sum = (sum + A[i]) % MOD
	}

	fmt.Fprintln(out, ans)
}

func readInt(r *bufio.Reader) int {
	var n int
	for {
		b, err := r.ReadByte()
		if err != nil || b < '0' || b > '9' {
			break
		}
		n = n*10 + int(b-'0')
	}
	return n
}

// End of Code
