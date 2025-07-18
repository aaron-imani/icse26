package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	sc.Scan()
	count, _ := strconv.Atoi(sc.Text())

	nums := make([]int, count)
	for i := 0; i < count; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		nums[i] = num
	}

	for i := count - 1; i >= 0; i-- {
		fmt.Print(nums[i])
		if i > 0 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

// End of Code
