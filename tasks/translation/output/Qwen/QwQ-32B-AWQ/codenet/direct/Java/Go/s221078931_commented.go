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

func (r IntegralRect) Diagonal() int {
	if r.Height >= r.Width {
		return 1<<31 - 1
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 200*200)
	index := 0
	for h := 1; h <= 200; h++ {
		for w := 1; w <= 200; w++ {
			rects[index] = IntegralRect{Height: h, Width: w}
			index++
		}
	}
	sort.Slice(rects, func(i, j int) bool {
		a := rects[i]
		b := rects[j]
		da := a.Diagonal()
		db := b.Diagonal()
		if da == db {
			return a.Height < b.Height
		}
		return da < db
	})

	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}
		line = strings.TrimSpace(line)
		if line == "0 0" {
			break
		}
		parts := strings.Fields(line)
		h, _ := strconv.Atoi(parts[0])
		w, _ := strconv.Atoi(parts[1])
		tmp := IntegralRect{Height: h, Width: w}
		tmpDiag := tmp.Diagonal()

		found := false
		for _, rect := range rects {
			diag := rect.Diagonal()
			if diag > tmpDiag || (diag == tmpDiag && rect.Height > tmp.Height) {
				fmt.Printf("%d %d\n", rect.Height, rect.Width)
				found = true
				break
			}
		}
	}
}

// End of Code
