package main

import (
	"bufio"
	"fmt"
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
		return 1<<31 - 1
	}
	return r.height*r.height + r.width*r.width
}

func (r *IntegralRect) Compare(o *IntegralRect) int {
	d1 := r.diagonal()
	d2 := o.diagonal()
	if d1 == d2 {
		return r.height - o.height
	}
	return d1 - d2
}

type ByDiagonal []*IntegralRect

func (a ByDiagonal) Len() int           { return len(a) }
func (a ByDiagonal) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByDiagonal) Less(i, j int) bool { return a[i].Compare(a[j]) < 0 }

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	rects := make([]*IntegralRect, 40000)
	index := 0
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[index] = &IntegralRect{i + 1, j + 1}
			index++
		}
	}
	sort.Sort(ByDiagonal(rects))

	for scanner.Scan() {
		input := strings.Split(scanner.Text(), " ")
		h, _ := strconv.Atoi(input[0])
		w, _ := strconv.Atoi(input[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := &IntegralRect{h, w}
		diag := tmpRect.diagonal()
		for i := 0; i < len(rects); i++ {
			if rects[i].Compare(tmpRect) > 0 {
				fmt.Println(rects[i].height, rects[i].width)
				break
			}
		}
	}
}
// End of Code
