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
		slove()
	}
}

func read(scanner *bufio.Scanner) bool {
	scanner.Scan()
	number, _ = strconv.Atoi(strings.TrimSpace(scanner.Text()))
	if number == 0 {
		return false
	}
	score = make([]int, number)
	scanner.Scan()
	input := strings.Fields(scanner.Text())
	for i := 0; i < number; i++ {
		score[i], _ = strconv.Atoi(input[i])
	}
	return true
}

func slove() {
	sort.Ints(score)
	sum := 0
	if number > 2 {
		for i := 1; i < number-1; i++ {
			sum += score[i]
		}
		fmt.Println(sum / (number - 2))
	} else {
		fmt.Println(0) // Handle the case where number is less than 3
	}
}
// End of Code
