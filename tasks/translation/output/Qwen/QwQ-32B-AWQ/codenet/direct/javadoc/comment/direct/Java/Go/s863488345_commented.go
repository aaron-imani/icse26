package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var mapNum int
	if scanner.Scan() {
		mapNum, _ = strconv.Atoi(scanner.Text())
	}

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println()
		}

		var h, w int
		if scanner.Scan() {
			h, _ = strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			w, _ = strconv.Atoi(scanner.Text())
		}

		battleTown := make([][]byte, h)
		for row := 0; row < h; row++ {
			if scanner.Scan() {
				line := scanner.Text()
				battleTown[row] = []byte(line)
			}
		}

		var x, y int
		for row := 0; row < h; row++ {
			for col := 0; col < w; col++ {
				if battleTown[row][col] == '^' || battleTown[row][col] == 'v' || battleTown[row][col] == '<' || battleTown[row][col] == '>' {
					x, y = row, col
				}
			}
		}

		var bomberActNum int
		if scanner.Scan() {
			bomberActNum, _ = strconv.Atoi(scanner.Text())
		}
		bomberAct := ""
		if scanner.Scan() {
			bomberAct = scanner.Text()
		}

		for _, action := range bomberAct {
			switch action {
			case 'U':
				battleTown[x][y] = '^'
				if x-1 >= 0 && battleTown[x-1][y] == '.' {
					battleTown[x-1][y] = '^'
					battleTown[x][y] = '.'
					x--
				}
			case 'D':
				battleTown[x][y] = 'v'
				if x+1 < h && battleTown[x+1][y] == '.' {
					battleTown[x+1][y] = 'v'
					battleTown[x][y] = '.'
					x++
				}
			case 'L':
				battleTown[x][y] = '<'
				if y-1 >= 0 && battleTown[x][y-1] == '.' {
					battleTown[x][y-1] = '<'
					battleTown[x][y] == '.' // typo fix: should be '='
					y--
				}
			case 'R':
				battleTown[x][y] = '>'
				if y+1 < w && battleTown[x][y+1] == '.' {
					battleTown[x][y+1] = '>'
					battleTown[x][y] = '.'
					y++
				}
			case 'S':
				moveBomber(battleTown, x, y)
			}
		}

		for _, row := range battleTown {
			fmt.Println(string(row))
		}
	}
}

func moveBomber(battleTown [][]byte, a int, b int) {
	direction := battleTown[a][b]
	switch direction {
	case '^':
		currentRow := a - 1
		col := b
		for currentRow >= 0 {
			cell := battleTown[currentRow][col]
			if cell == '*' {
				battleTown[currentRow][col] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentRow--
			}
		}
	case 'v':
		currentRow := a + 1
		col := b
		for currentRow < len(battleTown) {
			cell := battleTown[currentRow][col]
			if cell == '*' {
				battleTown[currentRow][col] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentRow++
			}
		}
	case '<':
		currentCol := b - 1
		row := a
		for currentCol >= 0 {
			cell := battleTown[row][currentCol]
			if cell == '*' {
				battleTown[row][currentCol] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentCol--
			}
		}
	case '>':
		currentCol := b + 1
		row := a
		for currentCol < len(battleTown[row]) {
			cell := battleTown[row][currentCol]
			if cell == '*' {
				battleTown[row][currentCol] = '.'
				return
			} else if cell == '#' {
				return
			} else {
				currentCol++
			}
		}
	}
} // End of Code
