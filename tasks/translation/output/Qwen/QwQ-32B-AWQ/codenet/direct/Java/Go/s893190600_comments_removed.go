package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var H, W int
	fmt.Fscanln(reader, &H, &W)

	grid := make([][]byte, H)
	for i := 0; i < H; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		grid[i] = []byte(line)
	}

	if H == 1 && W == 1 {
		fmt.Fprintln(writer, "No")
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
					fmt.Fprintln(writer, "No")
					return
				}
			}
		}
	}

	fmt.Fprintln(writer, "Yes")
}

// End of Code
