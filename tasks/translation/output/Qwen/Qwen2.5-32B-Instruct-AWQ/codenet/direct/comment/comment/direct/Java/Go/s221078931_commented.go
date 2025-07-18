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
		return int(^uint(0) >> 1)
	}
	return r.height*r.height + r.width*r.width
}

func (r *IntegralRect) compareTo(o *IntegralRect) int {
	d1 := r.diagonal()
	d2 := o.diagonal()
	if d1 == d2 {
		return r.height - o.height
	}
	return d1 - d2
}

func main() {
	var rects [40000]IntegralRect
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = IntegralRect{i + 1, j + 1}
		}
	}

	reader := bufio.NewReader(os.Stdin)
	for {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		if line == "0 0" {
			break
		}
		inputs := strings.Split(line, " ")
		h, _ := strconv.Atoi(inputs[0])
		w, _ := strconv.Atoi(inputs[1])

		tmpRect := IntegralRect{h, w}
		diag := tmpRect.diagonal()

		for _, rect := range rects {
			if rect.compareTo(&tmpRect) > 0 {
				fmt.Printf("%d %d\n", rect.height, rect.width)
				break
			}
		}
	}
}

// End of Code
