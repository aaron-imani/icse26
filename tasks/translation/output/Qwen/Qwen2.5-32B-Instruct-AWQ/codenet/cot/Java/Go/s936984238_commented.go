package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func main() {
	for read() {
		solve()
	}
}

func read() bool {
	var number int
	fmt.Scan(&number)
	if number == 0 {
		return false
	}

	score := make([]int, number)
	for i := 0; i < number; i++ {
		fmt.Scan(&score[i])
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
