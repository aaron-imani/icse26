package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	mapNum     int
	h, w       int
	battleTown [][]rune
	bomberActNum int
	bomberAct    []rune
	tank       [2]int
	xOfTank, yOfTank int
	xOfBomber, yOfBomber int
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	mapNum, _ = strconv.Atoi(sc.Text())

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println()
		}
		sc.Scan()
		line := strings.Split(sc.Text(), " ")
		h, _ = strconv.Atoi(line[0])
		w, _ = strconv.Atoi(line[1])

		battleTown = make([][]rune, h)
		for j := 0; j < h; j++ {
			sc.Scan()
			battleTown[j] = []rune(sc.Text())
			for k := 0; k < w; k++ {
				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					xOfTank = j
					yOfTank = k
				}
			}
		}

		sc.Scan()
		line = strings.Split(sc.Text(), " ")
		bomberActNum, _ = strconv.Atoi(line[0])
		bomberAct = []rune(line[1])

		for l := 0; l < bomberActNum; l++ {
			switch bomberAct[l] {
			case 'U':
				battleTown[xOfTank][yOfTank] = '^'
				if xOfTank-1 >= 0 && battleTown[xOfTank-1][yOfTank] == '.' {
					battleTown[xOfTank-1][yOfTank] = '^'
					battleTown[xOfTank][yOfTank] = '.'
					xOfTank--
				}
			case 'D':
				battleTown[xOfTank][yOfTank] = 'v'
				if xOfTank+1 < h && battleTown[xOfTank+1][yOfTank] == '.' {
					battleTown[xOfTank+1][yOfTank] = 'v'
					battleTown[xOfTank][yOfTank] = '.'
					xOfTank++
				}
			case 'L':
				battleTown[xOfTank][yOfTank] = '<'
				if yOfTank-1 >= 0 && battleTown[xOfTank][yOfTank-1] == '.' {
					battleTown[xOfTank][yOfTank-1] = '<'
					battleTown[xOfTank][yOfTank] = '.'
					yOfTank--
				}
			case 'R':
				battleTown[xOfTank][yOfTank] = '>'
				if yOfTank+1 < w && battleTown[xOfTank][yOfTank+1] == '.' {
					battleTown[xOfTank][yOfTank+1] = '>'
					battleTown[xOfTank][yOfTank] = '.'
					yOfTank++
				}
			case 'S':
				xOfBomber = xOfTank
				yOfBomber = yOfTank
				moveBomber(xOfBomber, yOfBomber)
			}
		}

		for s := 0; s < h; s++ {
			for k := 0; k < w; k++ {
				fmt.Printf("%c", battleTown[s][k])
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
