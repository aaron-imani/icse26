package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var numbers []int
	for scanner.Scan() {
		token := scanner.Text()
		num, _ := strconv.Atoi(token)
		numbers = append(numbers, num)
	}
	i := 0
	for i < len(numbers) {
		n := numbers[i]
		i++
		if n == 0 {
			break
		}
		scores := make([]int, n)
		for j := 0; j < n; j++ {
			scores[j] = numbers[i+j]
		}
		i += n
		sort.Ints(scores)
		sum := 0
		for j := 1; j < n-1; j++ {
			sum += scores[j]
		}
		avg := sum / (n-2)
		println(avg)
	}
}

// End of Code
