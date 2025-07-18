package main

import (
	"fmt"
)

func main() {
	var mapNum int
	fmt.Scan(&mapNum)
	for i := 0; i < mapNum; i++ {
		var h, w int
		fmt.Scan(&h, &w)
		grid := make([][]byte, h)
		for row := 0; row < h; row++ {
			var s string
			fmt.Scan(&s)
			grid[row] = []byte(s)
		}
		x, y := -1, -1
		for row := 0; row < h; row++ {
			for col := 0; col < w; col++ {
				c := grid[row][col]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x, y = row, col
					goto Found
				}
			}
		}
	Found:
		var actCount int
		var actions string
		fmt.Scan(&actCount)
		fmt.Scan(&actions)
		for _, action := range actions {
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
				shoot(grid, x, y)
			}
		}
		for _, row := range grid {
			fmt.Println(string(row))
		}
	}
}

func shoot(grid [][]byte, x, y int) {
	dir := grid[x][y]
	var dx, dy int
	switch dir {
	case '^':
		dx = -1
		dy = 0
	case 'v':
		dx = 1
		dy = 0
	case '<':
		dx = 0
		dy = -1
	case '>':
		dx = 0
		dy = 1
	}
	currentX := x + dx
	currentY := y + dy
	for {
		if currentX < 0 || currentX >= len(grid) || currentY < 0 || currentY >= len(grid[0]) {
			break
		}
		cell := grid[currentX][currentY]
		switch cell {
		case '*':
			grid[currentX][currentY] = '.'
			return
		case '#':
			return
		default:
			currentX += dx
			currentY += dy
		}
	}
}
// End of Code
