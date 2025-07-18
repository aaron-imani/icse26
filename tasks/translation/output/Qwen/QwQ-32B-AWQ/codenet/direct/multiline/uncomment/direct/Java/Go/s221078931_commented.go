package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"sort"
)

type IntegralRect struct {
	Height, Width int
}

func (r IntegralRect) Diagonal() int {
	if r.Height >= r.Width {
		return math.MaxInt32
	}
	return r.Height*r.Height + r.Width*r.Width
}

type ByDiagonalHeight []IntegralRect

func (a ByDiagonalHeight) Len() int {
	return len(a)
}
func (a ByDiagonalHeight) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
func (a ByDiagonalHeight) Less(i, j int) bool {
	di := a[i].Diagonal()
	dj := a[j].Diagonal()
	if di != dj {
		return di < dj
	}
	return a[i].Height < a[j].Height
}

func findFirstIndex(rects []IntegralRect, tmp IntegralRect) int {
	low := 0
	high := len(rects) - 1
	result := -1
	for low <= high {
		mid := (low + high) / 2
		r := rects[mid]
		dr := r.Diagonal()
		dt := tmp.Diagonal()
		if (dr > dt) || (dr == dt && r.Height > tmp.Height) {
			result = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return result
}

func main() {
	var rects []IntegralRect
	rects = make([]IntegralRect, 0, 200*200)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			h := i + 1
			w := j + 1
			rects = append(rects, IntegralRect{h, w})
		}
	}

	sort.Sort(ByDiagonalHeight(rects))

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) < 2 {
			continue
		}
		h, _ := strconv.Atoi(fields[0])
		w, _ := strconv.Atoi(fields[1])
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{h, w}
		index := findFirstIndex(rects, tmp)
		fmt.Printf("%d %d\n", rects[index].Height, rects[index].Width)
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}

// End of Code
