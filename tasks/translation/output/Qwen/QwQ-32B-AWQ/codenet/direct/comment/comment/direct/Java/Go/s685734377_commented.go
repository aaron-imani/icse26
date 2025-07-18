package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	grid := make([][]byte, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		grid[i] = []byte(line)
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
	for i := range hashRow {
		hashRow[i] = make([]int64, n)
	}
	hashCol := make([][]int64, n)
	for j := range hashCol {
		hashCol[j] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				exp := (j - k + n) % n
				hashRow[i][k] += int64(grid[i][j]) * powP[exp]
				exp2 := (i - k + n) % n
				hashCol[j][k] += int64(grid[i][j]) * powP[exp2]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B :=  öde 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				row := (i + A) % n
				col := (i + B) % n
				if hashRow[row][B] != hashCol[col][A] {
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
