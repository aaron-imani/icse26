package main

import (
	"fmt"
)

var (
	mapNum     int
	h, w       int
	battleTown [][]rune
	bomberActNum int
	bomberAct    []rune
	tank         [2]int
	xOfTank, yOfTank int
	xOfBomber, yOfBomber int
)

func main() {
	var n int
	fmt.Scan(&mapNum)

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println()
		}
		fmt.Scan(&h, &w)
		battleTown = make([][]rune, h)
		for j := range battleTown {
			var line string
			fmt.Scan(&line)
			battleTown[j] = []rune(line)
			for k, char := range battleTown[j] {
				if char == '^' || char == 'v' || char == '<' || char == '>' {
					tank[0], tank[1] = j, k
				}
			}
		}

		fmt.Scan(&bomberActNum)
		var act string
		fmt.Scan(&act)
		bomberAct = []rune(act)

		for _, action := range bomberAct {
			switch action {
			case 'U':
				battleTown[tank[0]][tank[1]] = '^'
				if tank[0]-1 >= 0 && battleTown[tank[0]-1][tank[1]] == '.' {
					battleTown[tank[0]-1][tank[1]] = '^'
					battleTown[tank[0]][tank[1]] = '.'
					tank[0]--
				}
			case 'D':
				battleTown[tank[0]][tank[1]] = 'v'
				if tank[0]+1 < h && battleTown[tank[0]+1][tank[1]] == '.' {
					battleTown[tank[0]+1][tank[1]] = 'v'
					battleTown[tank[0]][tank[1]] = '.'
					tank[0]++
				}
			case 'L':
				battleTown[tank[0]][tank[1]] = '<'
				if tank[1]-1 >= 0 && battleTown[tank[0]][tank[1]-1] == '.' {
					battleTown[tank[0]][tank[1]-1] = '<'
					battleTown[tank[0]][tank[1]] = '.'
					tank[1]--
				}
			case 'R':
				battleTown[tank[0]][tank[1]] = '>'
				if tank[1]+1 < w && battleTown[tank[0]][tank[1]+1] == '.' {
					battleTown[tank[0]][tank[1]+1] = '>'
					battleTown[tank[0]][tank[1]] = '.'
					tank[1]++
				}
			case 'S':
				xOfBomber, yOfBomber = tank[0], tank[1]
				moveBomber(xOfBomber, yOfBomber)
			}
		}

		for _, row := range battleTown {
			for _, cell := range row {
				fmt.Printf("%c", cell)
			}
			fmt.Println()
		}
	}
}

func moveBomber(a, b int) {
	if a < 0 || a >= h || b < 0 || b >= w {
		return
	}

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

// End of Code
