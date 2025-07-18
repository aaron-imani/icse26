package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type IntegralRect struct {
	height int
	width  int
}

func (r *IntegralRect) diagonal() int {
	if r.height >= r.width {
		return int(^uint(0) >> 1)
	}
	return r.height*r.height + r.width*r.width
}

type ByDiagonal []IntegralRect

func (a ByDiagonal) Len() int           { return len(a) }
func (a ByDiagonal) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByDiagonal) Less(i, j int) bool { return a[i].diagonal() < a[j].diagonal() }

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	rects := make([]IntegralRect, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = IntegralRect{i + 1, j + 1}
		}
	}
	sort.Sort(ByDiagonal(rects))

	for scanner.Scan() {
		input := scanner.Text()
		tmpArray := strings.Fields(input)

		h, _ := strconv.Atoi(tmpArray[0])
		w, _ := strconv.Atoi(tmpArray[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := IntegralRect{h, w}
		diag := tmpRect.diagonal()

		for i := 0; i < len(rects); i++ {
			if rects[i].diagonal() > diag {
				fmt.Printf("%d %d\n", rects[i].height, rects[i].width)
				break
			}
		}
	}
}

// End of Code
