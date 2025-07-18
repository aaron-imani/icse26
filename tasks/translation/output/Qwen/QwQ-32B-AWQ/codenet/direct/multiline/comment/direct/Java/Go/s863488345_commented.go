package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func fireShot(x int, y int, battleTown [][]byte) {
	direction := battleTown[x][y]
	switch direction {
	case '^':
		for currentX := x - 1; currentX >= 0; currentX-- {
			currentChar := battleTown[currentX][y]
			if currentChar == '*' {
				battleTown[currentX][y] = '.'
				return
			} else if currentChar == '#' {
				return
			}
		}
	case 'v':
		for currentX := x + 1; currentX < len(battleTown); currentX++ {
			currentChar := battleTown[currentX][y]
			if currentChar == '*' {
				battleTown[currentX][y] = '.'
				return
			} else if currentChar == '#' {
				return
			}
		}
	case '<':
		for currentY := y - 1; currentY >= 0; currentY-- {
			currentChar := battleTown[x][currentY]
			if currentChar == '*' {
				battleTown[x][currentY] = '.'
				return
			} else if currentChar == '#' {
				return
			}
		}
	case '>':
		for currentY := y + 1; currentY < len(battleTown[0]); currentY++ {
			currentChar := battleTown[x][currentY]
			if currentChar == '*' {
				battleTown[x][currentY] = '.'
				return
			} else if currentChar == '#' {
				return
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ := strconv.Atoi(scanner.Text())

	for mapIndex := 0; mapIndex < mapNum; mapIndex++ {
		scanner.Scan()
		h, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		w, _ := strconv.Atoi(scanner.Text())

		battleTown := make([][]byte, h)
		for i := 0; i < h; i++ {
			scanner.Scan()
			line := scanner.Text()
			battleTown[i] = []byte(line)
		}

		var x, y int
		found := false
		for i := 0; i < h; i++ {
			for j := 0; j < w; j++ {
				c := battleTown[i][j]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x, y = i, j
					found = true
					break
				}
			}
			if found {
				break
			}
		}

		scanner.Scan()
		bomberActNum, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		commands := scanner.Text()

		for i := 0; i < bomberActNum; i++ {
			cmd := commands[i]
			switch cmd {
			case 'U':
				battleTown[x][y] = '^'
				newX := x - 1
				if newX >= 0 && battleTown[newX][y] == '.' {
					battleTown[x][y] = '.'
					battleTown[newX][y] = '^'
					x = newX
				}
			case 'D':
				battleTown[x][y] = 'v'
				newX := x + 1
				if newX < h && battleTown[newX][y] == '.' {
					battleTown[x][y] = '.'
					battleTown[newX][y] = 'v'
					x = newX
				}
			case 'L':
				battleTown[x][y] = '<'
				newY := y - 1
				if newY >= 0 && battleTown[x][newY] == '.' {
					battleTown[x][y] = '.'
					battleTown[x][newY] = '<'
					y = newY
				}
			case 'R':
				battleTown[x][y] = '>'
				newY := y + 1
				if newY < w && battleTown[x][newY] == '.' {
					battleTown[x][y] = '.'
					battleTown[x][newY] = '>'
					y = newY
				}
			case 'S':
				fireShot(x, y, battleTown)
			}
		}

		for _, row := range battleTown {
			fmt.Println(string(row))
		}
		if mapIndex < mapNum-1 {
			fmt.Println()
		}
	}
}
// End of Code
