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

	var H, W int

	scanner.Scan()
	firstLine := scanner.Text()
	fields := strings.Fields(firstLine)
	H, _ = strconv.Atoi(fields[0])
	W, _ = strconv.Atoi(fields[1])

	grid := make([][]rune, H+2)
	for i := range grid {
		grid[i] = make([]rune, W+2)
	}

	for i := 1; i <= H; i++ {
		scanner.Scan()
		line := scanner.Text()
		for j := 1; j <= len(line); j++ {
			grid[i][j] = rune(line[j-1])
		}
	}

	if H == 1 && W == 1 {
		fmt.Println("No")
		return
	}

	found := false
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if grid[i][j] == '#' {
				if grid[i-1][j] != '#' &&
					grid[i+1][j] != '#' &&
					grid[i][j-1] != '#' &&
					grid[i][j+1] != '#' {
					found = true
					break
				}
			}
		}
		if found {
			break
		}
	}

	if found {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

// End of Code
