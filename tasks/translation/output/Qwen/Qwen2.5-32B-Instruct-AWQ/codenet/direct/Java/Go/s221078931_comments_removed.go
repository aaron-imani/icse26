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

func (r IntegralRect) diagonal() int {
	if r.height >= r.width {
		return int(^uint(0) >> 1) // Max int value
	}
	return r.height*r.height + r.width*r.width
}

func (r IntegralRect) compareTo(o IntegralRect) int {
	d1 := r.diagonal()
	d2 := o.diagonal()

	if d1 == d2 {
		return r.height - o.height
	}
	return d1 - d2
}

type IntegralRects []IntegralRect

func (r IntegralRects) Len() int           { return len(r) }
func (r IntegralRects) Less(i, j int) bool { return r[i].compareTo(r[j]) < 0 }
func (r IntegralRects) Swap(i, j int)      { r[i], r[j] = r[j], r[i] }

func main() {
	var rects []IntegralRect
	for i := 1; i <= 200; i++ {
		for j := 1; j <= 200; j++ {
			rects = append(rects, IntegralRect{height: i, width: j})
		}
	}
	sort.Sort(IntegralRects(rects))

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input := scanner.Text()
		tmpArray := strings.Fields(input)
		h, _ := strconv.Atoi(tmpArray[0])
		w, _ := strconv.Atoi(tmpArray[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := IntegralRect{height: h, width: w}
		diag := tmpRect.diagonal()

		for i := 0; i < len(rects); i++ {
			if rects[i].compareTo(tmpRect) > 0 {
				fmt.Printf("%d %d\n", rects[i].height, rects[i].width)
				break
			}
		}
	}
}

// End of Code
