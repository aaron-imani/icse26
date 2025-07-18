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
	scanner.Scan()
	firstLine := scanner.Text()
	parts := strings.Fields(firstLine)
	H, _ := strconv.Atoi(parts[0])
	W, _ := strconv.Atoi(parts[1])

	grid := make([]string, H)
	for i := 0; i < H; i++ {
		scanner.Scan()
		grid[i] = scanner.Text()
	}

	if H == 1 && W == 1 {
		if grid[0][0] == '#' {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if grid[i][j] == '#' {
				hasAdjacent := false

				if i-1 >= 0 && grid[i-1][j] == '#' {
					hasAdjacent = true
				}
				if i+1 < H && grid[i+1][j] == '#' {
					hasAdjacent = true
				}
				if j-1 >= 0 && grid[i][j-1] == '#' {
					hasAdjacent = true
				}
				if j+1 < W && grid[i][j+1] == '#' {
					hasAdjacent = true
				}

				if !hasAdjacent {
					fmt.Println("No")
					return
				}
			}
		}
	}

	fmt.Println("Yes")
}

// End of Code
