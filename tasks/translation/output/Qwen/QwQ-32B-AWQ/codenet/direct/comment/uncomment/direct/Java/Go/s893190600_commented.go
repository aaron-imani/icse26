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
	if !scanner.Scan() {
		fmt.Println("No")
		return
	}
	firstLine := scanner.Text()
	parts := strings.Fields(firstLine)
	H, _ := strconv.Atoi(parts[0])
	W, _ := strconv.Atoi(parts[1])

	grid := make([][]byte, H)
	for i := 0; i < H; i++ {
		if !scanner.Scan() {
			fmt.Println("No")
			return
		}
		line := scanner.Text()
		grid[i] = []byte(line)
	}

	if H == 1 && W == 1 {
		fmt.Println("No")
		return
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if grid[i][j] != '#' {
				continue
			}
			hasAdjacent := false

			if i > 0 && grid[i-1][j] == '#' {
				hasAdjacent = true
			}
			if i < H-1 && grid[i+1][j] == '#' {
				hasAdjacent = true
			}
			if j > 0 && grid[i][j-1] == '#' {
				hasAdjacent = true
			}
			if j < W-1 && grid[i][j+1] == '#' {
				hasAdjacent = true
			}

			if !hasAdjacent {
				fmt.Println("No")
				return
			}
		}
	}

	fmt.Println("Yes")
}

// End of Code
