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

	n, _ := readInt(reader)
	m, _ := readInt(reader)

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		num, _ := readInt(reader)
		str, _ := readString(reader)
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

	fmt.Fprintf(writer, "%d %d\n", correctAns, numPenal)
}

func readInt(reader *bufio.Reader) (int, error) {
	line, _, err := reader.ReadLine()
	if err != nil {
		return 0, err
	}
	num, err := strconv.Atoi(strings.TrimSpace(string(line)))
	return num, err
}

func readString(reader *bufio.Reader) (string, error) {
	line, _, err := reader.ReadLine()
	if err != nil {
		return "", err
	}
	return strings.TrimSpace(string(line)), nil
}

// End of Code
