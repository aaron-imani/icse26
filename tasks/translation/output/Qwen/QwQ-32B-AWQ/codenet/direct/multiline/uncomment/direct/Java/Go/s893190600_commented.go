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
	sc.Split(bufio.ScanLines)
	sc.Scan()
	firstLine := sc.Text()
	fields := strings.Fields(firstLine)
	H, _ := strconv.Atoi(fields[0])
	W, _ := strconv.Atoi(fields[1])

	grid := make([][]byte, H+2)
	for i := range grid {
		grid[i] = make([]byte, W+2)
	}

	for i := 1; i <= H; i++ {
		sc.Scan()
		line := sc.Text()
		for j := 0; j < len(line); j++ {
			grid[i][j+1] = line[j]
		}
	}

	if H == 1 && W == 1 {
		fmt.Println("No")
		return
	}

	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if grid[i][j] == '#' {
				up := grid[i-1][j] != '#'
				down := grid[i+1][j] != '#'
				left := grid[i][j-1] != '#'
				right := grid[i][j+1] != '#'
				if up && down && left && right {
					fmt.Println("No")
					return
				}
			}
		}
	}

	fmt.Println("Yes")
}

// End of Code
