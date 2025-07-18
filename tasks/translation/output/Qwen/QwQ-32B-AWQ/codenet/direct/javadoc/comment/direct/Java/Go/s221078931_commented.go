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
		return 1 << 60 // a very large number
	}
	return r.height*r.height + r.width*r.width
}

func main() {
	rects := make([]IntegralRect, 0, 200*200)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			h := i + 1
			w := j + 1
			rects = append(rects, IntegralRect{h, w})
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := rects[i]
		b := rects[j]
		da := a.diagonal()
		db := b.diagonal()
		if da != db {
			return da < db
		}
		return a.height < b.height
	})

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) != 2 {
			continue
		}
		hStr, wStr := fields[0], fields[1]
		h, _ := strconv.Atoi(hStr)
		w, _ := strconv.Atoi(wStr)
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{h, w}
		tmpDiag := tmp.diagonal()

		for i := 0; i < len(rects); i++ {
			r := rects[i]
			rd := r.diagonal()
			if rd > tmpDiag || (rd == tmpDiag && r.height > tmp.height) {
				fmt.Printf("%d %d\n", r.height, r.width)
				break
			}
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}
}

// End of Code
