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
	tank       [2]int
	xOfTank, yOfTank int
	xOfBomber, yOfBomber int
	s, k               int
	a, b               int
	x, y               int
)

func main() {
	var sc *Scanner
	sc = NewScanner()
	mapNum = sc.nextInt()

	for i := 0; i < mapNum; i++ {
		if i > 0 && i < mapNum {
			fmt.Println("")
		}
		h = sc.nextInt()
		w = sc.nextInt()

		battleTown = make([][]rune, h)
		for j := range battleTown {
			battleTown[j] = make([]rune, w)
		}

		for j := 0; j < h; j++ {
			c := []rune(sc.next())
			for k := 0; k < w; k++ {
				battleTown[j][k] = c[k]

				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					x = j
					y = k
				}
			}
		}

		bomberActNum = sc.nextInt()
		bomberAct = []rune(sc.next())

		if x >= 0 && x < h && y >= 0 && y < w {
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
					fmt.Printf("%c", battleTown[s][k])
				}
				fmt.Println()
			}
		}
	}
}

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

type Scanner struct {
	r   []rune
	i   int
	n   int
	buf []byte
}

func NewScanner() *Scanner {
	s := &Scanner{}
	s.buf = make([]byte, 1024)
	s.i = 0
	s.n = 0
	return s
}

func (s *Scanner) next() string {
	for s.i >= s.n {
		s.i = 0
		var err error
		s.n, err = fmt.Scanln(&s.buf)
		if err != nil {
			panic(err)
		}
		s.r = []rune(string(s.buf))
	}
	for s.i < len(s.r) && s.r[s.i] == ' ' {
		s.i++
	}
	var j int
	for j = s.i; j < len(s.r) && s.r[j] != ' '; j++ {
	}
	s.i = j + 1
	return string(s.r[s.i:j])
}

func (s *Scanner) nextInt() int {
	str := s.next()
	num := 0
	for _, c := range str {
		num = num*10 + int(c-'0')
	}
	return num
}

// End of Code
