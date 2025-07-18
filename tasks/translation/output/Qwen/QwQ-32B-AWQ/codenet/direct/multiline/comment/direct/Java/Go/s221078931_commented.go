package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"sort"
)

type IntegralRect struct {
	Height int
	Width  int
}

const MaxInt = 1<<31 - 1

func (r *IntegralRect) diagonal() int {
	if r.Height >= r.Width {
		return MaxInt
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 0, 200*200)
	for h := 1; h <= 200; h++ {
		for w := 1; w <= 200; w++ {
			rects = append(rects, IntegralRect{Height: h, Width: w})
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := rects[i]
		b := rects[j]
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
		tmpDiag := tmp.diagonal()

		found := false
		for i := 0; i < len(rects); i++ {
			rect := rects[i]
			diag := rect.diagonal()
			if diag > tmpDiag {
				fmt.Printf("%d %d\n", rect.Height, rect.Width)
				found = true
				break
			} else if diag == tmpDiag {
				if rect.Height > tmp.Height {
					fmt.Printf("%d %d\n", rect.Height, rect.Width)
					found = true
					break
				}
			}
		}
	}
}

// End of Code
