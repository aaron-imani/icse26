package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	nStr := scanner.Text()
	N, _ := strconv.Atoi(nStr)

	nums := make([]int, N)

	for i := 0; i < N; i++ {
		scanner.Scan()
		numStr := scanner.Text()
		num, _ := strconv.Atoi(numStr)
		nums[i] = num
	}

	if N == 0 {
		fmt.Println(0)
		return
	}

	max := nums[0]
	min := nums[0]

	for _, num := range nums {
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}

	fmt.Println(max - min)
}

// End of Code
