package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func lowerBound(arr []int64, t int64) int {
	min, max := 0, len(arr)
	for min < max {
		mid := (min + max) / 2
		if arr[mid] >= t {
			max = mid
		} else {
			min = mid + 1
		}
	}
	return min
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	data, _ := os.Stdin.ReadAll()
	tokens := strings.Fields(string(data))
	idx := 0

	getInt := func() int {
		v, _ := strconv.Atoi(tokens[idx])
		idx++
		return v
	}

	getInt64 := func() int64 {
		v, _ := strconv.ParseInt(tokens[idx], 10, 64)
		idx++
		return v
	}

	a := getInt()
	b := getInt()
	q := getInt()

	s := make([]int64, a+2)
	s[0] = -10000000000
	s[a+1] = 20000000000
	for i := 1; i <= a; i++ {
		s[i] = getInt64()
	}

	t := make([]int64, b+2)
	t[0] = -10000000000
	t[b+1] = 20000000000
	for i := 1; i <= b; i++ {
		t[i] = getInt64()
	}

	for i := 0; i < q; i++ {
		x := getInt64()
		posS := lowerBound(s, x+1)
		prevS := posS - 1
		if prevS < 0 {
			prevS = 0
		}
		sl := x - s[prevS]

		posT := lowerBound(t, x+1)
		prevT := posT - 1
		if prevT < 0 {
			prevT = 0
		}
		tl := x - t[prevT]

		posS2 := lowerBound(s, x)
		sr := s[posS2] - x

		posT2 := lowerBound(t, x)
		tr := t[posT2] - x

		opts := []int64{
			max(sl, tl),
			max(sr, tr),
			2*sl + tr,
			2*tl + sr,
			sl + 2*tr,
			tl + 2*sr,
		}

		minVal := opts[0]
		for _, v := range opts[1:] {
			if v < minVal {
				minVal = v
			}
		}

		fmt.Println(minVal)
	}
}
// End of Code
