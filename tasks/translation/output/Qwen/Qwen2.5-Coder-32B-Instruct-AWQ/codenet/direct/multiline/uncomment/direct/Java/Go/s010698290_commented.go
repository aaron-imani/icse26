package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	mStr, _ := reader.ReadString('\n')
	m, _ := strconv.Atoi(strings.TrimSpace(mStr))

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Fields(line)
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

	correctAns := 0
	numPenal := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correctAns++
			numPenal += penal[i]
		}
	}

	fmt.Fprintf(writer, "%d %d\n", correctAns, numPenal)
}

// End of Code
