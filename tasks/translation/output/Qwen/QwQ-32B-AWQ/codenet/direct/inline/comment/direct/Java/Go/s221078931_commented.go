import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type IntegralRect struct {
	Height int
	Width  int
}

func (r *IntegralRect) Diagonal() int {
	if r.Height >= r.Width {
		return math.MaxInt32
	}
	return r.Height*r.Height + r.Width*r.Width
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
		da := a.Diagonal()
		db := b.Diagonal()
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
		parts := strings.Fields(string(line))
		if len(parts) != 2 {
			continue
		}
		h, _ := strconv.Atoi(parts[0])
		w, _ := strconv.Atoi(parts[1])
		if h == 0 && w == 0 {
			break
		}
		tmp := IntegralRect{Height: h, Width: w}
		tmpDiag := tmp.Diagonal()

		low, high := 0, len(rects)
		for low < high {
			mid := (low + high) / 2
			a := rects[mid]
			da := a.Diagonal()
			if da > tmpDiag || (da == tmpDiag && a.Height > tmp.Height) {
				high = mid
			} else {
				low = mid + 1
			}
		}

		if low < len(rects) {
			fmt.Printf("%d %d\n", rects[low].Height, rects[low].Width)
		}
	}
}

// End of Code
