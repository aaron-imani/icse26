package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"sort"
)

const MaxInt = 2147483647

type IntegralRect struct {
	Height int
	Width  int
}

func (r *IntegralRect) diagonal() int {
	if r.Height >= r.Width {
		return MaxInt
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 0, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			h := i + 1
			w := j + 1
			rects = append(rects, IntegralRect{Height: h, Width: w})
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := &rects[i]
		b := &rects[j]
		d1 := a.diagonal()
		d2 := b.diagonal()
		if d1 != d2 {
			return d1 < d2
		}
		return a.Height < b.Height
	})

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) != 2 {
			continue
		}
		hStr := fields[0]
		wStr := fields[1]
		h, _ := strconv.Atoi(hStr)
		w, _ := strconv.Atoi(wStr)
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{Height: h, Width: w}
		diag := tmp.diagonal()
		found := false
		for i := 0; i < len(rects); i++ {
			r := rects[i]
			d1 := r.diagonal()
			h1 := r.Height
			h2 := tmp.Height
			if (d1 > diag) || (d1 == diag && h1 > h2) {
				fmt.Printf("%d %d\n", r.Height, r.Width)
				found = true
				break
			}
		}
	}
}
// End of Code
