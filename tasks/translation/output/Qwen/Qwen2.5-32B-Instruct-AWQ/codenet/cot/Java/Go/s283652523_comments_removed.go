package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1e9 + 7

func solve(in *bufio.Reader, out *bufio.Writer) {
	N, _ := strconv.Atoi(readLine(in))
	A := readIntArray(in, N)

	ans := 0
	sum := A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans += (sum * A[i]) % int(MOD)
		ans %= int(MOD)
		sum += A[i]
		sum %= int(MOD)
	}
	fmt.Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve(in, out)
}

func readLine(r *bufio.Reader) string {
	line, _ := r.ReadString('\n')
	return line[:len(line)-1]
}

func readIntArray(r *bufio.Reader, n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(readLine(r))
	}
	return arr
}

// End of Code
