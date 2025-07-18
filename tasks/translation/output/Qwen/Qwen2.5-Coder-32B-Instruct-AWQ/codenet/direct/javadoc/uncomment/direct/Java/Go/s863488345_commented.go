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
	var sc *Scanner = NewScanner()
	mapNum = sc.nextInt()

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			fmt.Println()
		}
		h = sc.nextInt()
		w = sc.nextInt()

		battleTown = make([][]rune, h)
		for j := range battleTown {
			battleTown[j] = make([]rune, w)
			line := sc.next()
			for k, char := range line {
				battleTown[j][k] = char

				if char == '^' || char == 'v' || char == '<' || char == '>' {
					xOfTank = j
					yOfTank = k
				}
			}
		}

		bomberActNum = sc.nextInt()
		bomberAct = []rune(sc.next())

		if 0 <= xOfTank && xOfTank < h && 0 <= yOfTank && yOfTank < w {
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
}

func moveBomber(a, b int) {
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

type Scanner struct {
	r   []rune
	i   int
	n   int
	err error
}

func NewScanner() *Scanner {
	s := &Scanner{}
	s.r = []rune{}
	s.i = 0
	s.n = 0
	s.err = nil
	return s
}

func (s *Scanner) next() string {
	if s.err != nil {
		return ""
	}
	for s.i >= s.n {
		var buf []byte
		buf, s.err = fmt.Scanln()
		if s.err != nil {
			return ""
		}
		s.r = []rune(string(buf))
		s.i = 0
		s.n = len(s.r)
	}
	start := s.i
	for s.i < s.n && s.r[s.i] != ' ' {
		s.i++
	}
	return string(s.r[start:s.i])
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
