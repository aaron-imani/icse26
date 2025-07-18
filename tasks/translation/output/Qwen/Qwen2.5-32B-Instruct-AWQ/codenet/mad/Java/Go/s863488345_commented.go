package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mapNum int
var h, w int
var battleTown [][]rune
var bomberActNum int
var bomberAct []rune
var tankX, tankY int
var bomberX, bomberY int
var x, y int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ = strconv.Atoi(scanner.Text())

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println("")
		}
		scanner.Scan()
		h, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		w, _ = strconv.Atoi(scanner.Text())

		// Initialize the battle town map
		battleTown = make([][]rune, h)
		for j := 0; j < h; j++ {
			scanner.Scan()
			battleTown[j] = []rune(scanner.Text())
			for k := 0; k < w; k++ {
				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					x = j
					y = k
				}
			}
		}

		scanner.Scan()
		bomberActNum, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		bomberAct = []rune(scanner.Text())

		// Process each action in the bomber's action list
		for l := 0; l < bomberActNum; l++ {
			switch bomberAct[l] {
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
					battleTown[x][y] = '.'
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
				bomberX = x
				bomberY = y
				moveBomber(bomberX, bomberY)
			}
		}

		// Print the final state of the battle town map
		for s := 0; s < h; s++ {
			for k := 0; k < w; k++ {
				fmt.Print(string(battleTown[s][k]))
			}
			fmt.Println()
		}
	}
}

// moveBomber handles the movement of the bomber's shot in the specified direction
func moveBomber(a, b int) {
	if a >= 0 && a < h && b >= 0 && b < w {
		switch battleTown[a][b] {
		case '^':
			for i := a - 1; i >= 0; i-- {
				if battleTown[i][b] == '*' {
					battleTown[i][b] = '.'
					return
				} else if battleTown[i][b] == '#' {
					return
				}
				a = i
			}
		case 'v':
			for i := a + 1; i < h; i++ {
				if battleTown[i][b] == '*' {
					battleTown[i][b] = '.'
					return
				} else if battleTown[i][b] == '#' {
					return
				}
				a = i
			}
		case '<':
			for i := b - 1; i >= 0; i-- {
				if battleTown[a][i] == '*' {
					battleTown[a][i] = '.'
					return
				} else if battleTown[a][i] == '#' {
					return
				}
				b = i
			}
		case '>':
			for i := b + 1; i < w; i++ {
				if battleTown[a][i] == '*' {
					battleTown[a][i] = '.'
					return
				} else if battleTown[a][i] == '#' {
					return
				}
				b = i
			}
		}
	}
}
// End of Code
