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

func (r IntegralRect) diagonal() int {
	if r.height >= r.width {
		return int(^uint(0) >> 1) // Max int value
	}
	return r.height*r.height + r.width*r.width
}


type ByDiagonal []IntegralRect

func (a ByDiagonal) Len() int           { return len(a) }
func (a ByDiagonal) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByDiagonal) Less(i, j int) bool {
	d1 := a[i].diagonal()
	d2 := a[j].diagonal()
	if d1 == d2 {
		return a[i].height < a[j].height
	}
	return d1 < d2
}

func main() {
	var rects [40000]IntegralRect
	for i := 0; i < 200; i++ {
		for j :=  0; j < 200; j++ {
			rects[i*200+j] = IntegralRect{i + 1, j + 1}
		}
	}
	sort.Sort(ByDiagonal(rects[:]))

	scanner := bufio.NewScanner(os.Stdin)
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
