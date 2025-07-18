package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([][]rune, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		a[i] = []rune(line)
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
	for i := range hashCol {
		hashCol[i] = make([]int64, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				val := int64(a[i][j])
				jMinusK := (j - k + n) % n
				hashRow[i][k] += val * powP[jMinusK]
				iMinusK := (i - k + n) % n
				hashCol[j][k] += val * powP[iMinusK]
			}
		}
	}

	var ans int
	for A := 0; A < n; A++ {
		for B := 0; B < n; B++ {
			ok := true
			for i := 0; i < n; i++ {
				rowIdx := (i + A) % n
				colIdx := (i + B) % n
				if hashRow[rowIdx][B] != hashCol[colIdx][A] {
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
