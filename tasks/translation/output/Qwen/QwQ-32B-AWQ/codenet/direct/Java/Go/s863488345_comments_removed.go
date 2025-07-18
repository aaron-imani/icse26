package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	mapNum int
	h, w   int
	battleTown [][]byte
	bomberAct []byte
	x, y   int // current tank position
)

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func moveBomber(a int, b int) {
	if a < 0 || a >= h || b < 0 || b >= w {
		return
	}
	c := battleTown[a][b]
	switch c {
	case '^':
		for i := a - 1; i >= 0; i-- {
			if a <= 0 {
				return
			}
			currentCell := battleTown[i][b]
			if currentCell == '*' {
				battleTown[i][b] = '.'
				return
			} else if currentCell == '#' {
				return
			} else {
				a--
				if a == 0 {
					return
				}
			}
		}
	case 'v':
		for i := a + 1; i < h; i++ {
			if a >= h {
				return
			}
			currentCell := battleTown[i][b]
			if currentCell == '*' {
				battleTown[i][b] = '.'
				return
			} else if currentCell == '#' {
				return
			} else {
				a++
				if a == h {
					return
				}
			}
		}
	case '<':
		for i := b - 1; i >= 0; i-- {
			if b <= 0 {
				return
			}
			currentCell := battleTown[a][i]
			if currentCell == '*' {
				battleTown[a][i] = '.'
				return
			} else if currentCell == '#' {
				return
			} else {
				b--
				if b == 0 {
					return
				}
			}
		}
	case '>':
		for i := b + 1; i < w; i++ {
			if b >= w {
				return
			}
			currentCell := battleTown[a][i]
			if currentCell == '*' {
				battleTown[a][i] = '.'
				return
			} else if currentCell == '#' {
				return
			} else {
				b++
				if b == w {
					return
				}
			}
		}
	default:
		return
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	mapNum = nextInt(sc)
	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println()
		}
		h = nextInt(sc)
		w = nextInt(sc)
		battleTown = make([][]byte, h)
		x, y = 0, 0 // reset positions
		for j := 0; j < h; j++ {
			sc.Scan()
			line := sc.Text()
			battleTown[j] = []byte(line)
			for k := 0; k < len(battleTown[j]); k++ {
				c := battleTown[j][k]
				if c == '^' || c == 'v' || c == '<' || c == '>' {
					x = j
					y = k
				}
			}
		}
		bomberActNum := nextInt(sc)
		sc.Scan()
		actionStr := sc.Text()
		bomberAct = make([]byte, bomberActNum)
		for l := 0; l < bomberActNum; l++ {
			bomberAct[l] = actionStr[l]
		}

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
				moveBomber(x, y)
			}
		}
		// Print the grid
		for _, row := range battleTown {
			fmt.Println(string(row))
		}
	}
}

// End of Code
