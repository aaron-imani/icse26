package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	parts := strings.Split(arrStr, " ")

	var arr []int
	for _, p := range parts {
		num, _ := strconv.Atoi(p)
		arr = append(arr, num)
	}

	max := 0
	output := 0
	for _, num := range arr {
		if num >= max {
			max = num
			output++
		}
	}

	fmt.Println(output)
}

// End of Code
