package main

import (
	"fmt"
	"sort"
)

var sc = fmt.Scan

func main() {
	var number int
	for {
		sc(&number)
		if number == 0 {
			break
		}
		score := make([]int, number)
		for i := range score {
			sc(&score[i])
		}
		solve(score, number)
	}
}

func solve(score []int, number int) {
	sort.Ints(score)
	sum := 0
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}

// End of Code
