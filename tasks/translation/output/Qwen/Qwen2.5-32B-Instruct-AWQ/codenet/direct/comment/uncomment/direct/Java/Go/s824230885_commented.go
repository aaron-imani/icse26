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

	N := nextInt(scanner)
	list := make([]int, N)
	for i := 0; i < N; i++ {
		list[i] = nextInt(scanner)
	}

	max := 0
	output := 0
	for _, value := range list {
		if max <= value {
			max = value
			output++
		}
	}
	fmt.Println(output)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// End of Code
