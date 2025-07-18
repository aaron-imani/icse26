package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func lowerBound(arr []int64, target int64) int {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var tokens []int64
	for scanner.Scan() {
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		tokens = append(tokens, num)
	}

	ptr := 0
	a := int(tokens[ptr])
	ptr++
	b := int(tokens[ptr])
	ptr++
	q := int(tokens[ptr])
	ptr++

	s := make([]int64, a+2)
	s[0] = -10000000000
	for i := 0; i < a; i++ {
		s[i+1] = tokens[ptr]
		ptr++
	}
	s[a+1] = 20000000000

	t := make([]int64, b+2)
	t[0] = -10000000000
	for i := 0; i < b; i++ {
		t[i+1] = tokens[ptr]
		ptr++
	}
	t[b+1] = 20000000000

	for i := 0; i < q; i++ {
		x := tokens[ptr]
		ptr++

		targetSPlus := x + 1
		lbS := lowerBound(s, targetSPlus)
		prevSIndex := lbS - 1
		if prevSIndex < 0 {
			prevSIndex = 0
		}
		sl := x - s[prevSIndex]

		targetTPlus := x + 1
		lbT := lowerBound(t, targetTPlus)
		prevTIndex := lbT - 1
		if prevTIndex < 0 {
			prevTIndex = 0
		}
		tl := x - t[prevTIndex]

		lbSx := lowerBound(s, x)
		srVal := s[lbSx] - x

		lbTx := lowerBound(t, x)
		trVal := t[lbTx] - x

		option1 := max(sl, tl)
		option2 := max(srVal, trVal)
		option3 := 2*sl + trVal
		option4 := 2*tl + srVal
		option5 := sl + 2*trVal
		option6 := tl + 2*srVal

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

// End of Code
