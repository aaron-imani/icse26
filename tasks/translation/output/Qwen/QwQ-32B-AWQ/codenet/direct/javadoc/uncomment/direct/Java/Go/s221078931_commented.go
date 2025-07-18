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

func (r IntegralRect) compareTo(other IntegralRect) int {
	da := r.Diagonal()
	db := other.Diagonal()
	if da == db {
		return r.Height - other.Height
	}
	return da - db
}

func main() {
	var rects []IntegralRect
	for h := 1; h <= 200; h++ {
		for w := 1; w <= 200; w++ {
			rects = append(rects, IntegralRect{Height: h, Width: w})
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a := rects[i]
		b := rects[j]
		return a.compareTo(b) < 0
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
		found := false
		for _, r := range rects {
			if r.compareTo(tmp) > 0 {
				fmt.Printf("%d %d\n", r.Height, r.Width)
				found = true
				break
			}
		}
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading input:", err)
	}
}

// End of Code
