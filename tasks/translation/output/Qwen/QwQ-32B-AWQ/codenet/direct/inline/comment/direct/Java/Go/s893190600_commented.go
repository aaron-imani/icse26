package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	h := nextInt(sc)
	w := nextInt(sc)
	if h == 1 && w == 1 {
		fmt.Println("No")
		return
	}

	grid := make([][]byte, h+2)
	for i := range grid {
		grid[i] = make([]byte, w+2)
	}

	for i := 1; i <= h; i++ {
		line := nextString(sc)
		for j := 1; j <= w; j++ {
			grid[i][j] = line[j-1]
		}
	}

	for i := 1; i <= h; i++ {
		for j := 1; j <= w; j++ {
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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

// End of Code
