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
	Height int
	Width  int
}

func (r *IntegralRect) diagonal() int {
	if r.Height >= r.Width {
		return 2147483647 // math.MaxInt32
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 0, 40000)
	for h := 1; h <= 200; h++ {
		for w := 1; w <= 200; w++ {
			rects = append(rects, IntegralRect{Height: h, Width: w})
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := &rects[i]
		b := &rects[j]
		da := a.diagonal()
		db := b.diagonal()
		if da == db {
			return a.Height < b.Height
		}
		return da < db
	})

	reader := bufio.NewReader(os.Stdin)
	for {
		line, _, err := reader.ReadLine()
		if err != nil {
			break
		}
		lineStr := strings.TrimSpace(string(line))
		if lineStr == "" {
			continue
		}
		parts := strings.Fields(lineStr)
		if len(parts) !=  = 2 {
			continue
		}
		h, _ := strconv.Atoi(parts[0])
		w, _ := strconv.Atoi(parts[1])
		if h == 0 && w == 0 {
			break
		}

		tmp := IntegralRect{Height: h, Width: w}
		diag := tmp.diagonal()

		found := false
		for i := 0; i < len(rects); i++ {
			r := rects[i]
			if r.diagonal() > diag {
				fmt.Printf("%d %d\n", r.Height, r.Width)
				found = true
				break
			}
		}
	}
}

// End of Code
