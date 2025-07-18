package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type IntegralRect struct {
	height int
	width  int
}

func (r *IntegralRect) diagonal() int {
	if r.height >= r.width {
		return 1<<31 - 1
	}
	return r.height*r.height + r.width*r.width
}

func (r *IntegralRect) CompareTo(o *IntegralRect) int {
	d1 := r.diagonal()
	d2 := o.diagonal()
	if d1 == d2 {
		return r.height - o.height
	}
	return d1 - d2
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	rects := make([]*IntegralRect, 40000)
	index := 0
	for i := 1; i <= 200; i++ {
		for j := 1; j <= 200; j++ {
			rects[index] = &IntegralRect{i, j}
			index++
		}
	}

	for i := 0; i < len(rects)-1; i++ {
		for j := i + 1; j < len(rects); j++ {
			if rects[i].CompareTo(rects[j]) > 0 {
				rects[i], rects[j] = rects[j], rects[i]
			}
		}
	}

	for {
		scanner.Scan()
		input := strings.Split(scanner.Text(), " ")
		h, _ := strconv.Atoi(input[0])
		w, _ := strconv.Atoi(input[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := &IntegralRect{h, w}
		diag := tmpRect.diagonal()
		for i := 0; i < len(rects); i++ {
			if rects[i].CompareTo(tmpRect) > 0 {
				fmt.Println(rects[i].height, rects[i].width)
				break
			}
		}
	}
}

// End of Code
