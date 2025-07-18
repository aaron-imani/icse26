package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the size of the matrix
	n, _ := strconv.Atoi(readLine(reader))
	a := make([][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = []rune(readLine(reader))
	}

	// Constants for hash calculation
	P, Q := int64(37), int64(47)
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0], powQ[0] = 1, 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	// Initialize hash arrays
	rowHashes := make([][]int64, n)
	colHashes := make([][]int64, n)
	for i := range rowHashes {
		rowHashes[i] = make([]int64, n)
		colHashes[i] = make([]int64, n)
	}

	// Calculate hash values for rows and columns
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				rowHashes[i][k] += int64(a[i][j]) * powP[(j-k+n)%n]
				colHashes[j][k] += int64(a[i][j]) * powP[(i-k+n)%n]
			}
		}
	}

	// Count the number of valid rotations
	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				if rowHashes[(i+A)%n][B] != colHashes[(i+B)%n][A] {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Fprintln(writer, ans)
}

// Helper function to read a line from the input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// End of Code
