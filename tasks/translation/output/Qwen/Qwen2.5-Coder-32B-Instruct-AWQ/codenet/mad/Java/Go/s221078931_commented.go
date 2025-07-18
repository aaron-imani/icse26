package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

type IntegralRect struct {
	height int
	width  int
}

func (r *IntegralRect) diagonal() int {
	if r.height >= r.width {
		return math.MaxInt32
	}
	return r.height*r.height + r.width*r.width
}

type ByDiagonal []*IntegralRect

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
	scanner := bufio.NewScanner(os.Stdin)

	rects := make([]*IntegralRect, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = &IntegralRect{i + 1, j + 1}
		}
	}
	sort.Sort(ByDiagonal(rects))

	for scanner.Scan() {
		tmpArray := strings.Split(scanner.Text(), " ")
		h, _ := strconv.Atoi(tmpArray[0])
		w, _ := strconv.Atoi(tmpArray[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := &IntegralRect{h, w}
		for i := 0; i < len(rects); i++ {
			if rects[i].diagonal() > tmpRect.diagonal() {
				fmt.Println(rects[i].height, rects[i].width)
				break
			}
		}
	}
}

// End of Code
