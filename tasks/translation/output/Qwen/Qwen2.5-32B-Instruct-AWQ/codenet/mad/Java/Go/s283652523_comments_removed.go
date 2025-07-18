package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1e9 + 7

func solve(reader *bufio.Reader, writer *bufio.Writer) {
	N, _ := strconv.Atoi(readLine(reader))
	A := readIntArray(reader, N)

	ans := int64(0)
	sum := int64(A[N-1])
	for i := N - 2; i >= 0; i-- {
		ans += (sum * int64(A[i])) % MOD
		ans %= MOD
		sum += int64(A[i])
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

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readIntArray(reader *bufio.Reader, n int) []int {
	line, _ := reader.ReadString('\n')
	arr := strings.Fields(line)
	intArr := make([]int, n)
	for i := 0; i < n; i++ {
		intArr[i], _ = strconv.Atoi(arr[i])
	}
	return intArr
}

// End of Code
