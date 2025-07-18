// Negative's code with corrections
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

func (r IntegralRect) Diagonal() int {
	if r.Height >= r.Width {
		return 1<<31 - 1 // Matches Java's Integer.MAX_VALUE
	}
	return r.Height*r.Height + r.Width*r.Width
}

func main() {
	rects := make([]IntegralRect, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = IntegralRect{Height: i + 1, Width: j + 1}
		}
	}

	sort.Slice(rects, func(i, j int) bool {
		a, b := rects[i], rects[j]
		if a.Diagonal() != b.Diagonal() {
			return a.Diagonal() < b.Diagonal()
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
		h, _ := strconv.Atoi(fields[0])
		w, _ := strconv.Atoi(fields[1])
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{Height: h, Width: w}

		found := false
		for _, r := range rects {
			if (r.Diagonal() > tmp.Diagonal()) || 
			(r.Diagonal() == tmp.Diagonal() && r.Height > tmp.Height) {
				fmt.Printf("%d %d\n", r.Height, r.Width)
				found = true
				break
			}
		}
		if !found {
			fmt.Println()
		}
	}

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}
// End of Code
