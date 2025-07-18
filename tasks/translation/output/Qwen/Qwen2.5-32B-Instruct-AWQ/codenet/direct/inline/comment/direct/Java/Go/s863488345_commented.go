package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var (
	mapNum     int
	h          int
	w          int
	battleTown [][]rune
	bomberActNum int
	bomberAct  []rune
	xOfTank    int
	yOfTank    int
	xOfBomber  int
	yOfBomber  int
	x          int
	y          int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	mapNum, _ = fmt.Sscanf(scanner.Text(), "%d", &mapNum)

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println("")
		}
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &h, &w)
		battleTown = make([][]rune, h)
		for j := range battleTown {
			battleTown[j] = make([]rune, w)
		}

		for j := 0; j < h; j++ {
			scanner.Scan()
			c := []rune(scanner.Text())
			for k := 0; k < w; k++ {
				battleTown[j][k] = c[k]

				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					x = j
					y = k
				}
			}
		}

		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &bomberActNum)
		scanner.Scan()
		bomberAct = []rune(scanner.Text())

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
				xOfBomber = x
				yOfBomber = y
				moveBomber(xOfBomber, yOfBomber)
			}
		}

		for s := 0; s < h; s++ {
			for k := 0; k < w; k++ {
				fmt.Print(string(battleTown[s][k]))
			}
			fmt.Println()
		}
	}
}

func moveBomber(a int, b int) {
	if 0 <= a && a < h && 0 <= b && b < w {
		switch battleTown[a][b] {
		case '^':
			for i := a - 1; i >= 0; i-- {
				if battleTown[i][b] == '*' {
					battleTown[i][b] = '.'
					return
				} else if battleTown[i][b] == '#' {
					return
				}
			}
		case 'v':
			for i := a + 1; i < h; i++ {
				if battleTown[i][b] == '*' {
					battleTown[i][b] = '.'
					return
				} else if battleTown[i][b] == '#' {
					return
				}
			}
		case '<':
			for i := b - 1; i >= 0; i-- {
				if battleTown[a][i] == '*' {
					battleTown[a][i] = '.'
					return
				} else if battleTown[a][i] == '#' {
					return
				}
			}
		case '>':
			for i := b + 1; i < w; i++ {
				if battleTown[a][i] == '*' {
					battleTown[a][i] = '.'
					return
				} else if battleTown[a][i] == '#' {
					return
				}
			}
		}
	}
}
// End of Code
