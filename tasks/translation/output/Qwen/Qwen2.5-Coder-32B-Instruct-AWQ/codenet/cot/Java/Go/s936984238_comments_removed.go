package main

import (
	"fmt"
	"sort"
)

var score []int
var number int

func main() {
	for read() {
		solve()
	}
}

func read() bool {
	_, err := fmt.Scanf("%d", &number)
	if err != nil || number == 0 {
		return false
	}

	score = make([]int, number)
	for i := 0; i < number; i++ {
		fmt.Scanf("%d", &score[i])
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
