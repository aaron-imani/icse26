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
	scanner.Scan()
	firstLine := scanner.Text()
	parts := strings.Split(firstLine, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	solved := make([]bool, n+1)
	penal := make([]int, n+1)

	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		num, _ := strconv.Atoi(parts[0])
		str := parts[1]

		if str == "A" {
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
		}
	}

	correct := 0
	totalPenal := 0
	for problem := 1; problem <= n; problem++ {
		if solved[problem] {
			correct++
			totalPenal += penal[problem]
		}
	}

	fmt.Printf("%d %d\n", correct, totalPenal)
}

// End of Code
