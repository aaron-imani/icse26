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
	scanner.Split(bufio.ScanWords)

	if !scanner.Scan() {
		fmt.Println("Error reading input")
		return
	}
	n, err := strconv.Atoi(scanner.Text())
	if err != nil {
		fmt.Println("Error parsing n:", err)
		return
	}

	if !scanner.Scan() {
		fmt.Println("Error reading input")
		return
	}
	m, err := strconv.Atoi(scanner.Text())
	if err != nil {
		fmt.Println("Error parsing m:", err)
		return
	}

	penal := make([]int, n+1)
	solved := make([]bool, n+1)

	for i := 0; i < m; i++ {
		if !scanner.Scan() {
			fmt.Println("Error reading input")
			return
		}
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Println("Error parsing num:", err)
			return
		}

		if !scanner.Scan() {
			fmt.Println("Error reading input")
			return
		}
		str := scanner.Text()

		if str[0] == 'A' {
			solved[num] = true
		} else if !solved[num] {
			penal[num]++
		}
	}

	correct_ans := 0
	num_penal := 0
	for i := 1; i <= n; i++ {
		if solved[i] {
			correct_ans++
			num_penal += penal[i]
		}
	}

	fmt.Printf("%d %d\n", correct_ans, num_penal)
}

// End of Code
