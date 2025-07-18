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

	var n, m int
	_, err := fmt.Fscanf(reader, "%d %d\n", &n, &m)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error reading input: %v\n", err)
		return
	}

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		var num int
		var str string
		_, err := fmt.Fscanf(reader, "%d %s\n", &num, &str)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Error reading input: %v\n", err)
			return
		}
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

	_, err = fmt.Fprintf(writer, "%d %d\n", correctAns, numPenal)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error writing output: %v\n", err)
		return
	}
}

// End of Code
