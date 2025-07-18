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

	if !sc.Scan() {
		panic("no first line")
	}
	firstLine := sc.Text()
	fields := strings.Fields(firstLine)
	H, _ := strconv.Atoi(fields[0])
	W, _ := strconv.Atoi(fields[1])

	if H == 1 && W == 1 {
		fmt.Println("No")
		return
	}

	grid := make([][]rune, H)
	for i := 0; i < H; i++ {
		if !sc.Scan() {
			panic("can't read line")
		}
		line := sc.Text()
		line = strings.TrimSpace(line)
		if len(line) != W {
			panic("invalid line length")
		}
		grid[i] = []rune(line)
	}

	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if grid[i][j] == '#' {
				hasAdj := false
				// Check up
				if i > 0 && grid[i-1][j] == '#' {
					hasAdj = true
				}
				// Check down
				if i < H-1 && grid[i+1][j] == '#' {
					hasAdj = true
				}
				// Check left
				if j > 0 && grid[i][j-1] == '#' {
					hasAdj = true
				}
				// Check right
				if j < W-1 && grid[i][j+1] == '#' {
					hasAdj = true
				}
				if !hasAdj {
					fmt.Println("No")
					return
				}
			}
		}
	}
	fmt.Println("Yes")
}

// End of Code
