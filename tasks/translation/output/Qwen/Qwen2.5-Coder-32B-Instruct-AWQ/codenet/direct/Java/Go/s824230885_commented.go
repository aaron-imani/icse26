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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	CONVSTR := map[int]string{
		8: " ",
		9: "\n",
		0: "",
	}

	next := func() string {
		line, _ := reader.ReadString('\n')
		return strings.TrimSpace(line)
	}

	hasNext := func() bool {
		return true // In Go, we typically handle EOF in the reading process
	}

	nextInt := func() int {
		str := next()
		num, _ := strconv.Atoi(str)
		return num
	}

	nextIntArray := func() []int {
		str := next()
		parts := strings.Split(str, CONVSTR[8])
		var nums []int
		for _, part := range parts {
			num, _ := strconv.Atoi(part)
			nums = append(nums, num)
		}
		return nums
	}

	N := nextInt()
	list := nextIntArray()
	max := 0
	output := 0
	for i := 0; i < N; i++ {
		if max <= list[i] {
			max = list[i]
			output++
		}
	}
	fmt.Fprintln(writer, output)
}

// End of Code
