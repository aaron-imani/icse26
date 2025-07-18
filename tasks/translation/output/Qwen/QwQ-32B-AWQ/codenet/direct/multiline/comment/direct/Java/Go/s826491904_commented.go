package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var parts []string
	for scanner.Scan() {
		parts = append(parts, scanner.Text())
	}
	N, _ := strconv.Atoi(parts[0])
	var max, min int
	firstNum, _ := strconv.Atoi(parts[1])
	max = firstNum
	min = firstNum
	for i := 2; i <= N; i++ {
		num, _ := strconv.Atoi(parts[i])
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}
	fmt.Println(max - min)
}

// End of Code
