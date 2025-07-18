package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	a := readInt(scanner)
	b := readInt(scanner)
	fmt.Println(max(0, a-2*b))
}

// End of Code
