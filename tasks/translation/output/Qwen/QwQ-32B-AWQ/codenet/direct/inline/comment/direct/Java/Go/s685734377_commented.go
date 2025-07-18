package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	var n int
	if !in.Scan() {
		fmt.Fprintln(os.Stderr, "Error reading input")
		os.Exit(1)
	}
	n, _ = strconv.Atoi(in.Text())

	grid := make([][]rune, n)
	for i := 0; i < n; i++ {
		if !in.Scan() {
			fmt.Fprintln(os.Stderr, "Error reading grid line")
			os.Exit(1)
		}
		grid[i] = []rune(in.Text())
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
	for i := range hashRow {
		hashRow[i] = make([]int64, n)
	}
	for j := range hashCol {
		hashCol[j] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				exponent := (j - k + n) % n
				hashRow[i][k] += int64(grid[i][j]) * powP[exponent]
				exponent2 := (i - k + n) % n
				hashCol[j][k] += int64(grid[i][j]) * powQ[exponent2]
			}
		}
	}

	ans := 0
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
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
