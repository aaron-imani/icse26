package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < mapNum; i++ {
		scanner.Scan()
		hw := strings.Fields(scanner.Text())
		h, _ := strconv.Atoi(hw[0])
		w, _ := strconv.Atoi(hw[1])

		battleTown := make([][]byte, h)
		var x, y int
		for row := 0; row < h; row++ {
			scanner.Scan()
			line := scanner.Text()
			battleTown[row] = []byte(line)
			for col := range battleTown[row] {
				c := battleTown[row][col]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x, y = row, col
				}
			}
		}

		scanner.Scan()
		bomberActNum, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		bomberAct := scanner.Text()

		for l := 0; l < bomberActNum; l++ {
			cmd := bomberAct[l]
			switch cmd {
			case 'U':
				battleTown[x][y] = '^'
				if x > 0 && battleTown[x-1][y] == '.' {
					battleTown[x-1][y] = '^'
					battleTown[x][y] = '.'
					x--
				}
			case 'D':
				battleTown[x][y] = 'v'
				if x < h-1 && battleTown[x+1][y] == '.' {
					battleTown[x+1][y] = 'v'
					battleTown[x][y] = '.'
					x++
				}
			case 'L':
				battleTown[x][y] = '<'
				if y > 0 && battleTown[x][y-1] == '.' {
					battleTown[x][y-1] = '<'
					battleTown[x][y] = '.'
					y--
				}
			case 'R':
				battleTown[x][y] = '>'
				if y < w-1 && battleTown[x][y+1] == '.' {
					battleTown[x][y+1] = '>'
					battleTown[x][y] = '.'
					y++
				}
			case 'S':
				moveBomber(x, y, battleTown)
			}
		}

		for _, row := range battleTown {
			fmt.Println(string(row))
		}
		if i < mapNum-1 {
			fmt.Println()
		}
	}
}

func moveBomber(a, b int, bt [][]byte) {
	dir := bt[a][b]
	switch dir {
	case '^':
		currentRow := a - 1
		col := b
		for currentRow >= 0 {
			c := bt[currentRow][col]
			if c == '*' {
				bt[currentRow][col] = '.'
				return
			} else if c == '#' {
				return
			}
			currentRow--
		}
	case 'v':
		currentRow := a + 1
		col := b
		for currentRow < len(bt) {
			c := bt[currentRow][col]
			if c == '*' {
				bt[currentRow][col] = '.'
				return
			} else if c == '#' {
				return
			}
			currentRow++
		}
	case '<':
		currentCol := b - 1
		row := a
		for currentCol >= 0 {
			c := bt[row][currentCol]
			if c == '*' {
				bt[row][currentCol] = '.'
				return
			} else if c == '#' {
				return
			}
			currentCol--
		}
	case '>':
		currentCol := b + 1
		row := a
		for currentCol < len(bt[row]) {
			c := bt[row][currentCol]
			if c == '*' {
				bt[row][currentCol] = '.'
				return
			} else if c == '#' {
				return
			}
			currentCol++
		}
	}
}
// End of Code
