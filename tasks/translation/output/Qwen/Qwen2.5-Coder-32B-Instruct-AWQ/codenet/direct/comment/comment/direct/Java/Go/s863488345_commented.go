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
			c := []rune(sc.next())
			for k := range c {
				battleTown[j][k] = c[k]

				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
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
	buf string
}

func NewScanner() *Scanner {
	s := new(Scanner)
	s.r = []rune{}
	s.i = 0
	s.n = 0
	s.buf = ""
	return s
}

func (s *Scanner) next() string {
	s.buf = ""
	for {
		if s.i >= s.n {
			s.r = []rune{}
			s.i = 0
			s.n, _ = fmt.Scanln(&s.buf)
			if s.n == 0 {
				return ""
			}
		}
		for ; s.i < s.n && s.r[s.i] == ' '; s.i++ {
		}
		if s.i >= s.n {
			continue
		}
		for ; s.i < s.n && s.r[s.i] != ' '; s.i++ {
			s.buf += string(s.r[s.i])
		}
		break
	}
	return s.buf
}

func (s *Scanner) nextInt() int {
	var n int
	fmt.Sscanf(s.next(), "%d", &n)
	return n
}

// End of Code
