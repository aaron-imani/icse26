package main

import (
	"bufio"
	"fmt"
	"os"
)

var mapNum int
var h int
var w int
var battleTown [][]rune
var bomberActNum int
var bomberAct []rune
var tank [2]int
var xOfTank int
var yOfTank int
var xOfBomber int
var yOfBomber int
var s int
var k int
var a int
var b int
var x int
var y int

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	mapNum, _ = strconv.Atoi(sc.Text())

	for i := 0; i < mapNum; i++ {
		if 1 <= i && i < mapNum {
			fmt.Println("")
		}
		sc.Scan()
		h, _ = strconv.Atoi(sc.Text())
		sc.Scan()
		w, _ = strconv.Atoi(sc.Text())

		battleTown = make([][]rune, h)
		for j := range battleTown {
			battleTown[j] = make([]rune, w)
		}

		for j := 0; j < h; j++ {
			sc.Scan()
			c := []rune(sc.Text())
			for k := 0; k < w; k++ {
				battleTown[j][k] = c[k]

				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					x = j
					y = k
				}
			}
		}

		sc.Scan()
		bomberActNum, _ = strconv.Atoi(sc.Text())
		sc.Scan()
		bomberAct = []rune(sc.Text())

		if 0 <= x && x <= h && 0 <= y && y <= w {
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
			for s = 0; s < h; s++ {
				for k = 0; k < w; k++ {
					fmt.Print(string(battleTown[s][k]))
				}
				fmt.Println()
			}
		}
	}
}

func moveBomber(a int, b int) {
	if 0 <= a && a <= h && 0 <= b && b <= w {
		if battleTown[a][b] == '^' {
			for i := a - 1; i >= 0; i-- {
				if a <= 0 {
					return
				}
				if battleTown[a-1][b] == '*' {
					battleTown[a-1][b] = '.'
					return
				} else if battleTown[a-1][b] == '#' {
					return
				} else {
					a--
					if a == 0 {
						return
					}
				}
			}
		}
		if battleTown[a][b] == 'v' {
			for i := a + 1; i < h; i++ {
				if battleTown[a+1][b] == '*' {
					battleTown[a+1][b] = '.'
					return
				} else if battleTown[a+1][b] == '#' {
					return
				} else {
					a++
					if a == h {
						return
					}
				}
			}
		}
		if battleTown[a][b] == '<' {
			for i := b - 1; i >= 0; i-- {
				if battleTown[a][b-1] == '*' {
					battleTown[a][b-1] = '.'
					return
				} else if battleTown[a][b-1] == '#' {
					return
				} else {
					b--
					if b == 0 {
						return
					}
				}
			}
		}
		if battleTown[a][b] == '>' {
			for i := b + 1; i < w; i++ {
				if battleTown[a][b+1] == '*' {
					battleTown[a][b+1] = '.'
					return
				} else if battleTown[a][b+1] == '#' {
					return
				} else {
					b++
					if b == w {
						return
					}
				}
			}
		}
	}
}
// End of Code
