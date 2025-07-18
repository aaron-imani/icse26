package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	data, err := os.Stdin.ReadAll()
	if err != nil {
		panic(err)
	}
	tokens := strings.Fields(string(data))
	i := 0
	a := atoi(tokens[i]); i++
	b := atoi(tokens[i]); i++
	q := atoi(tokens[i]); i++

	s := make([]int64, a+2)
	s[0] = -10000000000
	for j := 0; j < a; j++ {
		s[j+1] = ato64(tokens[i])
		i++
	}
	s[a+1] = 20000000000

	t := make([]int64, b+2)
	t[0] = -10000000000
	for j := 0; j < b; j++ {
		t[j+1] = ato64(tokens[i])
		i++
	}
	t[b+1] = 20000000000

	for ; i < len(tokens); {
		x := ato64(tokens[i])
		i++

		idxSPlus := lowerBound(s, x+1)
		prevS := idxSPlus - 1
		if prevS < 0 {
			prevS = 0
		}
		sl := x - s[prevS]

		idxTPlus := lowerBound(t, x+1)
		prevT := idxTPlus - 1
		if prevT < 0 {
			prevT = 0
		}
		tl := x - t[prevT]

		idxS := lowerBound(s, x)
		sr := s[idxS] - x

		idxT := lowerBound(t, x)
		tr := t[idxT] - x

		option1 := max(sl, tl)
		option2 := max(sr, tr)
		option3 := 2*sl + tr
		option4 := 2*tl + sr
		option5 := sl + 2*tr
		option6 := tl + 2*sr

		minVal := option1
		if option2 < minVal {
			minVal = option2
		}
		if option3 < minVal {
			minVal = option3
		}
		if option4 < minVal {
			minVal = option4
		}
		if option5 < minVal {
			minVal = option5
		}
		if option6 < minVal {
			minVal = option6
		}
		fmt.Println(minVal)
	}
}

func atoi(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

func ato64(s string) int64 {
	num, _ := strconv.ParseInt(s, 10, 64)
	return num
}

func lowerBound(arr []int64, target int64) int {
	min := 0
	max := len(arr)
	for min < max {
		mid := (min + max) / 2
		if arr[mid] >= target {
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

// End of Code
