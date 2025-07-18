package main

import (
	"fmt"
	"sort"
)

var sc = fmt.Scan

func main() {
	for read() {
		solve()
	}
}

var score []int
var number int

func read() bool {
	sc(&number)
	if number == 0 {
		return false
	}
	score = make([]int, number)
	for i := 0; i < number; i++ {
		sc(&score[i])
	}
	return true
}

func solve() {
	sort.Ints(score)
	sum := 0
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}

// End of Code
