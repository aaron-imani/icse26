package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	sc    = bufio.NewScanner(os.Stdin)
	score []int
)

func main() {
	for read() {
		solve()
	}
}

func read() bool {
	sc.Scan()
	line := sc.Text()
	number, err := strconv.Atoi(line)
	if err != nil || number == 0 {
		return false
	}

	score = make([]int, number)
	for i := 0; i < number; i++ {
		sc.Scan()
		score[i], _ = strconv.Atoi(sc.Text())
	}
	return true
}

func solve() {
	sort.Ints(score)
	sum := 0
	for i := 1; i < len(score)-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (len(score) - 2))
}

// End of Code
