package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func main() {
	for read() {
		solve()
	}
}

func read() bool {
	sc.Scan()
	number, _ := strconv.Atoi(sc.Text())
	if number == 0 {
		return false
	}

	score := make([]int, number)
	for i := 0; i < number; i++ {
		sc.Scan()
		score[i], _ = strconv.Atoi(sc.Text())
	}
	sort.Ints(score)
	// Store the sorted score slice in a global variable or pass it to solve function
	// For simplicity, we'll pass it directly to solve function
	solve(score)
	return true
}

func solve(score []int) {
	sum := 0
	for i := 1; i < len(score)-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (len(score) - 2))
}

// End of Code
