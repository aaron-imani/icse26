package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1e9 + 7

// solve reads the input and calculates the result based on the given logic.
func solve(reader *bufio.Reader, writer *bufio.Writer) {
	N, _ := strconv.Atoi(readLine(reader))
	A := readIntArray(reader, N)

	ans := int64(0)
	sum := int64(A[len(A)-1])
	for i := len(A) - 2; i >= 0; i-- {
		ans += (sum * int64(A[i])) % MOD
		ans %= MOD
		sum += int64(A[i])
		sum %= MOD
	}
	fmt.Fprintln(writer, ans)
}

// main function initializes the reader and writer and calls the solve function.
func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}

// readLine reads a line from the reader and trims any leading or trailing whitespace.
func readLine(reader *bufio.Reader) string {
	line, err := reader.ReadString('\n')
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading line: %v\n", err)
		os.Exit(1)
	}
	return strings.TrimSpace(line)
}

// readIntArray reads a line of integers from the reader and returns them as an array.
func readIntArray(reader *bufio.Reader, n int) []int {
	line, err := reader.ReadString('\n')
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading line: %v\n", err)
		os.Exit(1)
	}
	arr := strings.Fields(line)
	intArr := make([]int, n)
	for i := 0; i < n; i++ {
		intArr[i], err = strconv.Atoi(arr[i])
		if err != nil {
			fmt.Fprintf(os.Stderr, "Error converting to integer: %v\n", err)
			os.Exit(1)
		}
	}
	return intArr
}

// End of Code
