package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		num, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		str := scanner.Text()

		if str[0] == 'A' {
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
		}
	}

	correctAns := 0
	numPenal := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correctAns++
			numPenal += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correctAns, numPenal)
}

// End of Code
