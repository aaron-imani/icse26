package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func shoot(grid [][]byte, x, y int, direction byte) {
	var currentX, currentY int
	switch direction {
	case '^':
		currentX = x - 1
		currentY = y
		for currentX >= 0 {
			cell := grid[currentX][currentY]
			if cell == '*' {
				grid[currentX][currentY] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentX--
			}
		}
	case 'v':
		currentX = x + 1
		currentY = y
		if currentX >= len(grid) {
			return
		}
		for currentX < len(grid) {
			cell := grid[currentX][currentY]
			if cell == '*' {
				grid[currentX][currentY] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentX++
			}
		}
	case '<':
		currentX = x
		currentY = y - 1
		if currentY < 0 {
			return
		}
		for currentY >= 0 {
			cell := grid[currentX][currentY]
			if cell == '*' {
				grid[currentX][currentY] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentY--
			}
		}
	case '>':
		currentX = x
		currentY = y + 1
		if currentY >= len(grid[0]) {
			return
		}
		for currentY < len(grid[0]) {
			cell := grid[currentX][currentY]
			if cell == '*' {
				grid[currentX][currentY] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentY++
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < mapNum; i++ {
		scanner.Scan()
		h, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		w, _ := strconv.Atoi(scanner.Text())
		grid := make([][]byte, h)
		for j := 0; j < h; j++ {
			scanner.Scan()
			line := scanner.Text()
			grid[j] = []byte(line)
		}
		var x, y int
		var direction byte
	found:
		for row := 0; row < h; row++ {
			for col := 0; col < w; col++ {
				c := grid[row][col]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x = row
					y = col
					direction = c
					break found
				}
			}
		}
		scanner.Scan()
		bomberActNum, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		actions := scanner.Text()
		for _, action := range actions {
			switch action {
			case 'U':
				newDir := byte('^')
				nx := x - 1
				ny := y
				if nx >= 0 && grid[nx][ny] == '.' {
					grid[x][y] = '.'
					x = nx
					y = ny
					grid[x][y] = newDir
					direction = newDir
				} else {
					direction = newDir
				}
			case 'D':
				newDir := byte('v')
				nx := x + 1
				if nx < h && grid[nx][y] == '.' {
					grid[x][y] = '.'
					x = nx
					grid[x][y] = newDir
					direction = newDir
				} else {
					direction = newDir
				}
			case 'L':
				newDir := byte('<')
				ny := y - 1
				if ny >= 0 && grid[x][ny] == '.' {
					grid[x][y] = '.'
					y = ny
					grid[x][y] = newDir
					direction = newDir
				} else {
					direction = newDir
				}
			case 'R':
				newDir := byte('>')
				ny := y + 1
				if ny < w && grid[x][ny] == '.' {
					grid[x][y] = '.'
					y = ny
					grid[x][y] = newDir
					direction = newDir
				} else {
					direction = newDir
				}
			case 'S':
				shoot(grid, x, y, direction)
			}
		}
		for _, row := range grid {
			fmt.Println(string(row))
		}
		if i != mapNum-1 {
			fmt.Println()
		}
	}
}

// End of Code
