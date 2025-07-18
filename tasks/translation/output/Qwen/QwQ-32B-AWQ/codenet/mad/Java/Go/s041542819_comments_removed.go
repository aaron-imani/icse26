package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type LightScanner struct {
	tokens []string
	idx    int
}

func NewLightScanner(r io.Reader) *LightScanner {
	scanner := bufio.NewScanner(r)
	var tokens []string
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, " ")
		tokens = append(tokens, parts...)
	}
	return &LightScanner{tokens: tokens, idx: 0}
}

func (ls *LightScanner) Next() string {
	if ls.idx >= len(ls.tokens) {
		panic("no more tokens")
	}
	token := ls.tokens[ls.idx]
	ls.idx++
	return token
}

func (ls *LightScanner) NextInt() int {
	s := ls.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (ls *LightScanner) NextInt64() int64 {
	s := ls.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

type LightWriter struct {
	w       *bufio.Writer
	breaked bool
}

func NewLightWriter(w io.Writer) *LightWriter {
	return &LightWriter{
		w: bufio.NewWriter(w),
		breaked: true,
	}
}

func (lw *LightWriter) Print(s string) *LightWriter {
	_, _ = lw.w.WriteString(s)
	lw.breaked = false
	return lw
}

func (lw *LightWriter) Ans(s string) *LightWriter {
	if !lw.breaked {
		lw.Print(" ")
	}
	lw.Print(s)
	return lw
}

func (lw *LightWriter) Ansln(n int64) *LightWriter {
	lw.Ans(fmt.Sprint(n)).Ln()
	return lw
}

func (lw *LightWriter) Ln() *LightWriter {
	lw.Print("\n")
	lw.breaked = true
	return lw
}

func (lw *LightWriter) Close() error {
	return lw.w.Flush()
}

func Max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func MinInt64(vals ...int64) int64 {
	if len(vals) == 0 {
		panic("no elements provided")
	}
	minVal := vals[0]
	for _, v := range vals[1:] {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

func LowerBound(a []int64, t int64, min int) int {
	max := len(a)
	for min < max {
		mid := (min + max) / 2
		if t <= a[mid] {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

func main() {
	scanner := NewLightScanner(os.Stdin)
	writer := NewLightWriter(os.Stdout)

	a := scanner.NextInt()
	b := scanner.NextInt()
	q := scanner.NextInt()

	sArr := make([]int64, a+2)
	sArr[0] = -10000000000
	sArr[a+1] = 20000000000
	for i := 0; i < a; i++ {
		sArr[i+1] = scanner.NextInt64()
	}

	tArr := make([]int64, b+2)
	tArr[0] = -10000000000
	tArr[b+1] = 20000000000
	for i := 0; i < b; i++ {
		tArr[i+1] = scanner.NextInt64()
	}

	for i := 0; i < q; i++ {
		x := scanner.NextInt64()

		idxSPlus1 := LowerBound(sArr, x+1, 0)
		prevSIndex := idxSPlus1 - 1
		if prevSIndex < 0 {
			prevSIndex = 0
		}
		sl := x - sArr[prevSIndex]

		idxTPlus1 := LowerBound(tArr, x+1, 0)
		prevTIndex := idxTPlus1 - 1
		if prevTIndex < 0 {
			prevTIndex = 0
		}
		tl := x - tArr[prevTIndex]

		idxS := LowerBound(sArr, x, 0)
		sr := sArr[idxS] - x

		idxT := LowerBound(tArr, x, 0)
		tr := tArr[idxT] - x

		candidates := []int64{
			Max(sl, tl),
			Max(sr, tr),
			2*sl + tr,
			2*tl + sr,
			sl + 2*tr,
			tl + 2*sr,
		}

		minVal := MinInt64(candidates...)
		writer.Ansln(minVal)
	}

	writer.Close()
// End of Code
