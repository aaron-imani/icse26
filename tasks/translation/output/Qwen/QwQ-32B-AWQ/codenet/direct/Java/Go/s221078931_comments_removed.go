package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"sort"
	"strings"
)

type IntegralRect struct {
	Height int
	Width  int
}

func (r IntegralRect) diagonal() int {
	if r.Height >= r.Width {
		return math.MaxInt32
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 200*200)
	index := 0
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[index] = IntegralRect{Height: i + 1, Width: j + 1}
			index++
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a, b := rects[i], rects[j]
		da := a.diagonal()
		db := b.diagonal()
		if da == db {
			return a.Height < b.Height
		}
		return da < db
	})

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) != 2 {
			continue
		}
		h, _ := strconv.Atoi(fields[0])
		w, _ := strconv.Atoi(fields[1])
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{Height: h, Width: w}
		diagTmp := tmp.diagonal()
		found := false
		for i := 0; i < len(rects); i++ {
			r := rects[i]
			d := r.diagonal()
			if d > diagTmp || (d == diagTmp && r.Height > tmp.Height) {
				fmt.Printf("%d %d\n", r.Height, r.Width)
				found = true
				break
			}
		}
	}
}

// End of Code
