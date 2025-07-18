package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	grid := make([][]byte, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		grid[i] = []byte(scanner.Text())
	}

	P := int64(37)
	Q := int64(47)
	powP := make([]int64, n+1)
	powQ := make([]int64, n+1)
	powP[0] = 1
	powQ[0] = 1
	for i := 1; i <= n; i++ {
		powP[i] = powP[i-1] * P
		powQ[i] = powQ[i-1] * Q
	}

	hashRow := make([][]int64, n)
	hashCol := make([][]int64, n)
	for i := 0; i < n; i++ {
		hashRow[i] = make([]int64, n)
		hashCol[i] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				mod := (j - k + n) % n
				hashRow[i][k] += int64(grid[i][j]) * powP[mod]
				modCol := (i - k + n) % n
				hashCol[j][k] += int64(grid[i][j]) * powP[modCol]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				rowI := (i + A) % n
				colI := (i + B) % n
				if hashRow[rowI][B] != hashCol[colI][A] {
					ok = false
					break
				}
			}
			if ok {
				ans++
			}
		}
	}
	fmt.Println(ans)
}
// End of Code
