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
	if scanner.Scan() {
		line := scanner.Text()
		parts := strings.Fields(line)
		n, _ := strconv.Atoi(parts[0])
		m, _ := strconv.Atoi(parts[1])

		penalties := make([]int, n+1)
		solved := make([]bool, n+1)

		for i := 0; i < m; i++ {
			if scanner.Scan() {
				line := scanner.Text()
				parts := strings.Fields(line)
				num, _ := strconv.Atoi(parts[0])
				action := parts[1]

				if len(action) > 0 && action[0] == 'A' {
					solved[num] = true
				} else {
					if !solved[num] {
						penalties[num]++
					}
				}
			}
		}

		correctAns, numPenal := 0, 
		for i := 1; i <= n; i++ {
			if solved[i] {
				correctAns++
				numPenal += penalties[i]
			}
		}

		fmt.Printf("%d %d\n", correctAns, numPenal)
	}
}

// End of Code
