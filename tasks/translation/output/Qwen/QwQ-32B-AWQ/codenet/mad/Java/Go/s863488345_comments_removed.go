package main

import (
	"fmt"
)

func main() {
	var mapNum int
	fmt.Scan(&mapNum)
	for test := 0; test < mapNum; test++ {
		if test > 0 {
			fmt.Println()
		}
		var h, w int
		fmt.Scan(&h, &w)
		grid := make([][]byte, h)
		var x, y int
		for i := 0; i < h; i++ {
			var line string
			fmt.Scan(&line)
			grid[i] = []byte(line)
			for j := range grid[i] {
				c := grid[i][j]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x, y = i, j
				}
			}
		}
		var bomberActNum int
		var bomberAct string
		fmt.Scan(&bomberActNum)
		fmt.Scan(&bomberAct)
		for _, action := range bomberAct {
			switch action {
			case 'U':
				if x > 0 && grid[x-1][y] == '.' {
					grid[x][y] = '.'
					x--
					grid[x][y] = '^'
				}
			case 'D':
				if x < h-1 && grid[x+1][y] == '.' {
					grid[x][y] = '.'
					x++
					grid[x][y] = 'v'
				}
			case 'L':
				if y > 0 && grid[x][y-1] == '.' {
					grid[x][y] = '.'
					y--
					grid[x][y] = '<'
				}
			case 'R':
				if y < w-1 && grid[x][y+1] == '.' {
					grid[x][y] = '.'
					y++
					grid[x][y] = '>'
				}
			case 'S':
				moveBomber(grid, x, y, h, w)
			}
		}
		for _, row := range grid {
			fmt.Println(string(row))
		}
	}
}

func moveBomber(grid [][]byte, a, b, h, w int) {
	dir := grid[a][b]
	switch dir {
	case '^':
		currentA := a
		for currentA > 0 {
			currentA--
			if grid[currentA][b] == '*' {
				grid[currentA][b] = '.'
				return
			} else if grid[currentA][b] == '#' {
				return
			}
		}
	case 'v':
		currentA := a
		for currentA < h-1 {
			currentA++
			if grid[currentA][b] == '*' {
				grid[currentA][b] = '.'
				return
			} else if grid[currentA][b] == '#' {
				return
			}
		}
	case '<':
		currentB := b
		for currentB > 0 {
			currentB--
			if grid[a][currentB] == '*' {
				grid[a][currentB] = '.'
				return
			} else if grid[a][currentB] == '#' {
				return
			}
		}
	case '>':
		currentB := b
		for currentB < w-1 {
			currentB++
			if grid[a][currentB] == '*' {
				grid[a][currentB] = '.'
				return
			} else if grid[a][currentB] == '#' {
				return
			}
		}
	}
}
// End of Code
