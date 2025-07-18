package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	var H, W int
	if scanner.Scan() {
		fmt.Sscanf(scanner.Text(), "%d %d", &H, &W)
	}
	grid := make([][]rune, H+2) // 0-based with padding
	for i := range grid {
		grid[i] = make([]rune, W+2)
	}
	for i := 1; i <= H; i++ {
		if scanner.Scan() {
			line := scanner.Text()
			for j := 1; j <= W; j++ {
				grid[i][j] = rune(line[j-1])
			}
		}
	}
	ans := solve(grid, H, W)
	fmt.Println(ans)
}

func solve(grid [][]rune, H, W int) string {
	if H == 1 && W == 1 {
		return "No"
	}
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if grid[i][j] != '#' {
				continue
			}
			hasAdjacent := false
			if grid[i-1][j] == '#' || grid[i+1][j] == '#' ||
				grid[i][j-1] == '#' || grid[i][j+1] == '#' {
				hasAdjacent = true
			}
			if !hasAdjacent {
				return "No"
			}
		}
	}
	return "Yes"
}

// End of Code
