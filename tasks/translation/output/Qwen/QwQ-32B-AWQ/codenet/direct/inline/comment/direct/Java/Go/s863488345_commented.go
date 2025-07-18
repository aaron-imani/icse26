package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func handleShot(x, y int, bt [][]byte, h, w int) {
	dir := bt[x][y]
	dx, dy := 0, 0
	switch dir {
	case '^':
		dx = -1
	case 'v':
		dx = 1
	case '<':
		dy = -1
	case '>':
		dy = 1
	}

	currentX, currentY := x+dx, y+dy
	for {
		if currentX < 0 || currentX >= h || currentY < 0 || currentY >= w {
			break
		}
		cell := bt[currentX][currentY]
		if cell == '*' {
			bt[currentX][currentY] = '.'
			break
		} else if cell == '#' {
			break
		}
		currentX += dx
		currentY += dy
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

		battleTown := make([][]byte, h)
		var x, y int

		for j := 0; j < h; j++ {
			scanner.Scan()
			rowStr := scanner.Text()
			row := make([]byte, w)
			for k := 0; k < w; k++ {
				row[k] = rowStr[k]
				if row[k] == '^' || row[k] == 'v' || row[k] == '<' || row[k] == '>' {
					x = j
					y = k
				}
			}
			battleTown[j] = row
		}

		scanner.Scan()
		bomberActNum, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		bomberAct := scanner.Text()

		for l := 0; l < len(bomberAct); l++ {
			cmd := bomberAct[l]
			switch cmd {
			case 'U':
				battleTown[x][y] = '^'
				newX := x - 1
				newY := y
				if newX >= 0 && newX < h && newY >= 0 && newY < w {
					if battleTown[newX][newY] == '.' {
						battleTown[newX][newY] = '^'
						battleTown[x][y] = '.'
						x = newX
						y = newY
					}
				}
			case 'D':
				battleTown[x][y] = 'v'
				newX := x + 1
				if newX < h {
					if battleTown[newX][y] == '.' {
						battleTown[newX][y] = 'v'
						battleTown[x][y] = '.'
						x = newX
					}
				}
			case 'L':
				battleTown[x][y] = '<'
				newY := y - 1
				if newY >= 0 {
					if battleTown[x][newY] == '.' {
						battleTown[x][newY] = '<'
						battleTown[x][y] = '.'
						y = newY
					}
				}
			case 'R':
				battleTown[x][y] = '>'
				newY := y + 1
				if newY < w {
					if battleTown[x][newY] == '.' {
						battleTown[x][newY] = '>'
						battleTown[x][y] = '.'
						y = newY
					}
				}
			case 'S':
				handleShot(x, y, battleTown, h, w)
			}
		}

		for _, row := range battleTown {
			fmt.Println(string(row))
		}
		if i != mapNum-1 {
			fmt.Println()
		}
	}
}

// End of Code
