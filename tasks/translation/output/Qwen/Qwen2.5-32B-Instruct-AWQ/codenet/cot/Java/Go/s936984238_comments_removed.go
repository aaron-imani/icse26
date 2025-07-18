package main

import (
	"bufio"
	"fmt"
	"sort"
	"strings"
)

var sc = bufio.NewScanner(System.in)

var score []int
var number int

func main() {
	for read() {
		slove()
	}
}

func read() bool {
	sc.Scan()
	number, _ = strconv.Atoi(sc.Text())
	if number == 0 {
		return false
	}

	score = make([]int, number)
	for i := 0; i < number; i++ {
		sc.Scan()
		score[i], _ = strconv.Atoi(sc.Text())
	}
	return true
}

func slove() {
	sort.Ints(score)
	sum := 0
	for i := 1; i < number-1; i++ {
		sum += score[i]
	}
	fmt.Println(sum / (number - 2))
}

// End of Code
