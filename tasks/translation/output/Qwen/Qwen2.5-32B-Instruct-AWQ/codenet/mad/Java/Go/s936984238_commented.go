package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var score []int
var number int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for read(scanner) {
		solve()
	}
}

func read(scanner *bufio.Scanner) bool {
	scanner.Scan()
	number, err := strconv.Atoi(strings.TrimSpace(scanner.Text()))
	if err != nil || number == 0 {
		return false
	}
	score = make([]int, number)
	for i := 0; i < number; i++ {
		scanner.Scan()
		score[i], err = strconv.Atoi(strings.TrimSpace(scanner.Text()))
		if err != nil {
			fmt.Fprintf(os.Stderr, "Error parsing input: %v\n", err)
			return false
		}
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
