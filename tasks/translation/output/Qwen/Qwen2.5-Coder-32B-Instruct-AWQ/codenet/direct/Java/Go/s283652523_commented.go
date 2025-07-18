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

	ans := 0
	sum := A[N-1]
	for i := N - 2; i >= 0; i-- {
		ans = (ans + (sum*A[i])%MOD) % MOD
		sum = (sum + A[i]) % MOD
	}
	fmt.Fprintln(out, ans)
}

func readInt(in *bufio.Reader) int {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	num, _ := strconv.Atoi(line)
	return num
}

func readIntArray(in *bufio.Reader, n int) []int {
	line, _ := in.ReadString('\n')
	line = strings.TrimSpace(line)
	strs := strings.Split(line, " ")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strs[i])
	}
	return arr
}

// End of Code
