package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan() // Read first line for H and W
	line := sc.Text()
	fields := strings.Fields(line)
	H, _ := strconv.Atoi(fields[0])
	W, _ := strconv.Atoi(fields[1])

	if H == 1 && W == 1 {
		fmt.Println("No")
		return
	}

	lines := make([]string, H)
	for i := 0; i < H; i++ {
		sc.Scan()
		lines[i] = sc.Text()
	}

	// Initialize grid with H+2 rows, each of W+2 runes
	grid := make([][]rune, H+2)
	for i := range grid {
		grid[i] = make([]rune, W+2)
	}

	for i := 0; i < H; i++ {
		line := lines[i]
		for j := 0; j < len(line); j++ {
			grid[i+1][j+1] = rune(line[j])
		}
	}

	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if grid[i][j] == '#' {
				up := grid[i-1][j]
				down := grid[i+1][j]
				left := grid[i][j-1]
				right := grid[i][j+1]
				if up != '#' && down != '#' && left != '#' && right != '#' {
					fmt.Println("No")
					return
				}
			}
		}
	}

	fmt.Println("Yes")
}

// End of Code
