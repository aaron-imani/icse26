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

	N := readInt(in)
	A := readIntArray(in, N)

	ans, sum := 0, A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans = (ans + (sum*A[i])%MOD) % MOD
		sum = (sum + A[i]) % MOD
	}
	fmt.Fprintln(out, ans)
}

func readInt(r *bufio.Reader) int {
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(r)))
	return n
}

func readIntArray(r *bufio.Reader, n int) []int {
	line := strings.Fields(readLine(r))
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(line[i])
	}
	return arr
}

func readLine(r *bufio.Reader) string {
	buf := make([]byte, 0, 1000000)
	for {
		l, p, err := r.ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

// End of Code
