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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	nums := strings.Split(input, " ")

	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	c, _ := strconv.Atoi(nums[2])

	if a < b && b < c && a < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
// End of Code
