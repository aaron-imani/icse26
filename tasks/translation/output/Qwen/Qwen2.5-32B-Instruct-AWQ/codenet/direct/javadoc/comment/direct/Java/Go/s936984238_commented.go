package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var score []int
var number int

func main() {
	for read() {
		solve()
	}
}

func read() bool {
	sc.Scan()
	var err error
	number, err = strconv.Atoi(sc.Text())
	if number == 0 || err != nil {
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
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}
// End of Code
