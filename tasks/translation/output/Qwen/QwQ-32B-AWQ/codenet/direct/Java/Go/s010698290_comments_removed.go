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
	scanner.Split(bufio.ScanLines)

	var n, m int
	if scanner.Scan() {
		firstLine := scanner.Text()
		parts := strings.Fields(firstLine)
		n, _ = strconv.Atoi(parts[0])
		m, _ = strconv.Atoi(parts[1])
	}

	solved := make([]bool, n+1)
	penalty := make([]int, n+1)

	for i := 0; i < m; i++ {
		if scanner.Scan() {
			line := scanner.Text()
			parts := strings.Fields(line)
			num, _ := strconv.Atoi(parts[0])
			str := parts[1]

			if str == "A" {
				solved[num] = true
			} else {
				if !solved[num] {
					penalty[num]++
				}
			}
		}
	}

	correct := 0
	totalPenalty := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correct++
			totalPenalty += penalty[i]
		}
	}

	fmt.Printf("%d %d\n", correct, totalPenalty)
}

// End of Code
