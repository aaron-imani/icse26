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

	// Read the dimensions H and W
	var H, W int
	_, err := fmt.Fscan(reader, &H, &W)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading dimensions: %v\n", err)
		return
	}

	// Initialize the grid with extra padding
	C := make([][]rune, H+2)
	for i := range C {
		C[i] = make([]rune, W+2)
	}

	// Read the grid
	for i := 1; i <= H; i++ {
		line, err := reader.ReadString('\n')
		if err != nil {
			fmt.Fprintf(os.Stderr, "Error reading line: %v\n", err)
			return
		}
		line = strings.TrimSpace(line)
		for j := 1; j <= W; j++ {
			C[i][j] = rune(line[j-1])
		}
	}

	// Check if the grid is 1x1
	if H == 1 && W == 1 {
		fmt.Fprintln(writer, "No")
		return
	}

	// Check the condition for each cell
	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			if C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' && C[i][j-1] != '#' && C[i][j+1] != '#' {
				fmt.Fprintln(writer, "No")
				return
			}
		}
	}

	// If no condition is violated, print "Yes"
	fmt.Fprintln(writer, "Yes")
}
// End of Code
