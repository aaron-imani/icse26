package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var numbers []int
	for scanner.Scan() {
		txt := scanner.Text()
		num, _ := strconv.Atoi(txt)
		numbers = append(numbers, num)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "Error:", err)
		os.Exit(1)
	}
	i := 0
	for {
		if i >= len(numbers) {
			break
		}
		N := numbers[i]
		i++
		if N == 0 {
			break
		}
		if i+N > len(numbers) {
			break
		}
		score := make([]int, N)
		copy(score, numbers[i:i+N])
		i += N
		sort.Ints(score)
		sum := 0
		for j := 1; j < N-1; j++ {
			sum += score[j]
		}
		fmt.Println(sum / (N-2))
	}
}

// End of Code
