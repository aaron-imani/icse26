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
	fmt.Println(score)
	return true
}

func solve() {
	var sum int
	number := len(score)
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}

// End of Code
