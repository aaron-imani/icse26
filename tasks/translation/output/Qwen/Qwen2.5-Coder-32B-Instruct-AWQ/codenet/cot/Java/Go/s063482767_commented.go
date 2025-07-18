package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	queue := make([]int, 0, n)
	for i := 0; i < n; i++ {
		input, _ = reader.ReadString('\n')
		num, _ := strconv.Atoi(strings.TrimSpace(input))
		queue = append(queue, num)
		sort.Ints(queue) // Simulate priority queue by sorting
	}

	sum := 0
	for i := 0; i < n-1; i++ {
		sum += queue[0]
		queue = queue[1:]
	}

	// 出力
	if queue[0] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
