package main

import (
	"bufio"
	"os"
	"strconv"
)

var (
	mapNum int
	h, w int
	battleTown [][]byte
	bomberActNum int
	bomberAct []byte
	x, y int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	mapNum = nextInt(scanner)

	for i := 0; i < mapNum; i++ {
		if i > 0 {
			s := []byte{'\n'}
			os.Stdout.Write(s)
		}
		h = nextInt(scanner)
		w = nextInt(scanner)
		battleTown = make([][]byte, h)
		for j := 0; j < h; j++ {
			battleTown[j] = make([]byte, w)
			scanner.Scan()
			row := scanner.Bytes()
			for k := 0; k < w; k++ {
				battleTown[j][k] = row[k]
				if battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>' {
					x = j
					y = k
				}
			}
		}

		bomberActNum = nextInt(scanner)
		scanner.Scan()
		bomberAct = scanner.Bytes()

		if x >= 0 && x <= h-1 && y >= 0 && y <= w-1 {
			for l := 0; l < bomberActNum; l++ {
				cmd := bomberAct[l]
				switch cmd {
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
					if y-1 >=  getSupportFragmentManager().
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

			for s := 0; s < h; s++ {
				for k := 0; k < w; k++ {
					s := []byte{battleTown[s][k]}
					s.Write(s)
				}
				os.Stdout.Write([]byte{'\n'})
			}
		}
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func moveBomber(a, b int) {
	if a < 0 || a >= h || b < 0 || b >= w {
		return
	}

	switch battleTown[a][b] {
	case '^':
		currentA := a
		for {
			currentA--
			if currentA < 0 {
				break
			}
			cell := battleTown[currentA][b]
			switch cell {
			case '*':
				battleTown[currentA][b] = '.'
				return
			case '#':
				return
			default:
				continue
			}
		}
	case 'v':
		currentA := a
		for {
			currentA++
			if currentA >= h {
				break
			}
			cell := battleTown[currentA][b]
			switch cell {
			case '*':
				battleTown[currentA][b] = '.'
				return
			case '#':
				return
			default:
				continue
			}
		}
	case '<':
		currentB := b
		for {
			currentB--
			if currentB < 0 {
				break
			}
			cell := battleTown[a][currentB]
			switch cell {
			case '*':
				battleTown[a][currentB] = '.'
				return
			case '#':
				return
			default:
				continue
			}
		}
	case '>':
		currentB := b
		for {
			currentB++
			if currentB >= w {
				break
			}
			cell := battleTown[a][currentB]
			switch cell {
			case '*':
				battleTown[a][currentB] = '.'
				return
			case '#':
				return
			default:
				continue
			}
		}
	default:
		return
	}
}
// End of Code
