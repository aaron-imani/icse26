package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Rect struct {
	Height int
	Width  int
}

func (r Rect) Diagonal() int {
	if r.Height >= r.Width {
		return 2147483647 // Integer.MAX_VALUE
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]Rect, 0, 200*200)
	for h := 1; h <= 200; h++ {
		for w := 1; w <= 200; w++ {
			rect := Rect{Height: h, Width: w}
			rects = append(rects, rect)
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := rects[i]
		b := rects[j]
		aDiag := a.Diagonal()
		bDiag := b.Diagonal()
		if aDiag < bDiag {
			return true
		} else if aDiag == bDiag {
			return a.Height < b.Height
		}
		return false
	})

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if len(fields) != 2 {
			continue
		}
		h, err := strconv.Atoi(fields[0])
		if err != nil {
			fmt.Fprintln(os.Stderr, "Error parsing h:", err)
			continue
		}
		w, err := strconv.Atoi(fields[1])
		if err != nil {
			fmt.Fprintln(os.Stderr, "Error parsing w:", err)
			continue
		}
		if h == 0 && w == 激 {
			break
		}
		tmp := Rect{Height: h, Width: w}

		index := sort.Search(len(rects), func(i int) bool {
			current := rects[i]
			aDiag := current.Diagonal()
			bDiag := tmp.Diagonal()
			if aDiag < bDiag {
				return false
			} else if aDiag > bDiag {
				return true
			} else {
				return current.Height > tmp.Height
			}
		})

		if index < len(rects) {
			fmt.Printf("%d %d\n", rects[index].Height, rects[index].Width)
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
	}
}

// End of Code
