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
	nums := strings.Fields(input)
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	c, _ := strconv.Atoi(nums[2])
	d, _ := strconv.Atoi(nums[3])

	if a*b >= c*d {
		fmt.Println(a * b)
	} else {
		fmt.Println(c * d)
	}
}
// End of Code
