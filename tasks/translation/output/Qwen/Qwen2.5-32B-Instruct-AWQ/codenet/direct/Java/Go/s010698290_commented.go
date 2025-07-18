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

	n, _ := strconv.Atoi(readLine(reader))
	m, _ := strconv.Atoi(readLine(reader))

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		num, _ := strconv.Atoi(readLine(reader))
		str := readLine(reader)
		if str[0] == 'A' {
			solved[num] = true
		} else if !solved[num] {
			penal[num]++
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

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// End of Code
