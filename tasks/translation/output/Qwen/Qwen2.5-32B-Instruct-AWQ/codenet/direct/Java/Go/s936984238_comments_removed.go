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
	// Pass the score to solve function
	// We need to pass the score to the solve function
	// We can do this by modifying the solve function to accept score as a parameter
	// and then call it with the score array.
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
