package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	firstLine := scanner.Text()
	var n, m int
	fmt.Sscanf(firstLine, "%d %d", &n, &m)

	solved := make([]bool, n+1)
	penal := make([]int, n+1)

	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		fields := strings.Fields(line)
		num, _ := fmt.Atoi(fields[0])
		action := fields[1]

		if action[0] == 'A' { // Correctly checks for "AC"
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
		}
	}

	correctAns := 0
	numPenal := 0 // Fixed initialization
	for i := 1; i <= n; i++ {
		if solved[i] {
			correctAns++
			numPenal += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correctAns, numPenal)
}
// End of Code
