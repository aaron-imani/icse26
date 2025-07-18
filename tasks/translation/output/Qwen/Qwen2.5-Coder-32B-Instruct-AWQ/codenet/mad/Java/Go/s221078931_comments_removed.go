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

func (r *IntegralRect) diagonal() int {
	if r.height >= r.width {
		return 1<<31 - 1 // Integer.MAX_VALUE equivalent in Go
	}
	return r.height*r.height + r.width*r.width
}

func (r *IntegralRect) Less(o *IntegralRect) bool {
	d1 := r.diagonal()
	d2 := o.diagonal()

	if d1 == d2 {
		return r.height < o.height
	}
	return d1 < d2
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	rects := make([]*IntegralRect, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = &IntegralRect{i + 1, j + 1}
		}
	}

	// Sort rects using Go's sort package
	sort.Slice(rects, func(i, j int) bool {
		return rects[i].Less(rects[j])
	})

	for {
		scanner.Scan()
		input := strings.Split(scanner.Text(), " ")
		if len(input) < 2 {
			break
		}
		h, errH := strconv.Atoi(input[0])
		w, errW := strconv.Atoi(input[1])

		if errH != nil || errW != nil || h == 0 && w == 0 {
			break
		}

		tmpRect := &IntegralRect{h, w}

		for i := 0; i < len(rects); i++ {
			if rects[i].Less(tmpRect) == false {
				fmt.Println(rects[i].height, rects[i].width)
				break
			}
		}
	}
}

// End of Code
