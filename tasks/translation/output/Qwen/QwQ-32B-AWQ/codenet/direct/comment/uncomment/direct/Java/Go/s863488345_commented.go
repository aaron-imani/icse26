package main

import (
	"bufio"
	"fmt"
	"os"
	"runtime"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < mapNum; i++ {
		scanner.Scan()
		parts := strings.Fields(scanner.Text())
		h, _ := strconv.Atoi(parts[0])
		w, _ := strconv.Atoi(parts[1])

		grid := make([][]rune, h)
		for row := 0; row < h; row++ {
			scanner.Scan()
			line := scanner.Text()
			grid[row] = []rune(line)
		}

		var x, y int
		for row := 0; row < h; row++ {
			for col := 0; col < w; col++ {
				if grid[row][col] == '^' || grid[row][col] == 'v' || grid[row][col] == '<' || grid[row][col] == '>' {
					x = row
					y = col
				}
			}
		}

		scanner.Scan()
		bomberActNum, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		actions := scanner.Text()

		for l := 0; l < bomberActNum; l++ {
			action := rune(actions[l])
			switch action {
			case 'U':
				grid[x][y] = '^'
				if x-1 >= 0 && grid[x-1][y] == '.' {
					grid[x-1][y] = '^'
					grid[x][y] = '.'
					x--
				}
			case 'D':
				grid[x][y] = 'v'
				if x+1 < h && grid[x+1][y] == '.' {
					grid[x+1][y] = 'v'
					grid[x][y] = '.'
					x++
				}
			case 'L':
				grid[x][y] = '<'
				if y-1 >= 0 && grid[x][y-1] == '.' {
					grid[x][y-1] = '<'
					grid[x][y] = '.'
					y--
				}
			case 'R':
				grid[x][y] = '>'
				if y+1 < w && grid[x][y+1] == '.' {
					grid[x][y+1] = '>'
					grid[x][y] = '.'
					y++
				}
			case 'S':
				moveBomber(grid, x, y)
			}
		}

		for s := 0; s < h; s++ {
			for k := 0; k < w; k++ {
				fmt.Printf("%c", grid[s][k])
			}
			fmt.Println()
		}
		if i < mapNum-1 {
			fmt.Println()
		}
	}
}

func moveBomber(grid [][]rune, a int, b int) {
	direction := grid[a][b]
	switch direction {
	case '^':
		currentX := a
		for {
			newX := currentX - 1
			if newX < 0 {
				break
			}
			cell := grid[newX][b]
			if cell == '*' {
				grid[newX][b] = '.'
				return
			} else if cell == '#' {
				break
			}
			currentX = newX
		}
	case 'v':
		currentX := a
		for {
			newX := currentX + 1
			if newX >= len(grid) {
				break
			}
			cell := grid[newX][b]
			if cell == '*' {
				grid[newX][b] = '.'
				return
			} else if cell == '#' {
				break
			}
			currentX = newX
		}
	case '<':
		currentY := b
		for {
			newY := currentY - 1
			if newY < 0 {
				break
			}
			cell := grid[a][newY]
			if cell == '*' {
				grid[a][newY] = '.'
				return
			} else if cell == '#' {
				break
			}
			currentY = newY
		}
	case '>':
		currentY := b
		for {
			newY := currentY + 1
			if newY >= len(grid[0]) {
				break
			}
			cell := grid[a][newY]
			if cell == '*' {
				grid[a][newY] = '.'
				return
			} else if cell == '#' {
				break
			}
			currentY = newY
		}
	}
}

// End of Code
