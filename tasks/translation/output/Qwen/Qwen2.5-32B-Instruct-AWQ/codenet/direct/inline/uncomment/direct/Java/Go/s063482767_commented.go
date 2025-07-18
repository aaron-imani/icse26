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
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	var queue []int
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		queue = append(queue, num)
	}
	sort.Ints(queue)
	sum := 0
	for i := 0; i < n-1; i++ {
		sum += queue[i]
	}

	if queue[n-1] < sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
