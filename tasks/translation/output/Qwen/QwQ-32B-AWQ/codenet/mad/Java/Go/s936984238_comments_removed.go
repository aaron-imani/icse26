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
	var allNumbers []int
	for scanner.Scan() {
		token := scanner.Text()
		num, _ := strconv.Atoi(token)
		allNumbers = append(allNumbers, num)
	}
	idx := 0
	for {
		n := allNumbers[idx]
		idx++
		if n == 0 {
			break
		}
		if idx+n > len(allNumbers) {
			break
		}
		scores := allNumbers[idx : idx+n]
		idx += n
		sort.Ints(scores)
		sum := 0
		for i := 1; i < len(scores)-1; i++ {
			sum += scores[i]
		}
		fmt.Println(sum / (n-2))
	}
	// End of Code
