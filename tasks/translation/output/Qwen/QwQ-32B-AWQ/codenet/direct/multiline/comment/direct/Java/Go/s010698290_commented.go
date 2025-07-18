package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := makeScanner()
	n, m := readNM(scanner)

	solved := make([]bool, n+1)
	penal := make([]int, n+1)

	for i := 0; i < m; i++ {
		line := scanner.Scan()
		fields := strings.Fields(line)
		num, _ := strconv.Atoi(fields[0])
		action := fields[1]

		if action == "A" {
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
		}
	}

	correct, penalty := 0, 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correct++
			penalty += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correct, penalty)
}

func makeScanner() *Scanner {
	scanner := bufio.NewScanner(os.Stdin)
	return scanner
}

func readNM(scanner *Scanner) (int, int) {
	scanner.Scan()
	line := scanner.Text()
	fields := strings.Split(line, " ")
	n, _ := strconv.Atoi(fields[0])
	m, _ := strconv.Atoi(fields[1])
	return n, m
}

// Alternative using a helper struct for Scanner (if needed)
type Scanner struct {
	*bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanLines)
	return &Scanner{sc}
}

// But in the code above, using the standard bufio.Scanner directly is sufficient.

// Note: The code above may have a minor adjustment. Here's the direct version without helper:

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	fields := strings.Split(line, " ")
	n, _ := strconv.Atoi(fields[0])
	m, _ := strconv.Atoi(fields[1])

	solved := make([]bool, n+1)
	penal := make([]int, n+1)

	for i := 0; i < m; i++ {
		scanner.Scan()
		line := scanner.Text()
		fields := strings.Fields(line)
		num, _ := strconv.Atoi(fields[0])
		action := fields[1]

		if action == "A" {
			solved[num] = true
		} else {
			if !solved[num] {
				penal[num]++
			}
		}
	}

	correct, penalty := 0, 翻转0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correct++
			penalty += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correct, penalty)
}

// End of Code
